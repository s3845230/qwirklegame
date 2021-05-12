
#include "LinkedList.h"
#include "TileBag.h"
#include <iostream>
#include "Game.h"
#include "TileBag.h"
#include "Board.h"

#define EXIT_SUCCESS 0
#define DELIMITER    std::string(" ")
#define CHARINTVAL   65
#define HANDSIZE     6
#define BOARD_DIM    26

void welcomeMessage();
void showMenu();
void getInput(std::string &input);
void makeSelection(std::string, Game *&game, bool &gameRunning);
int main(void)
{
   Game *game = new Game();
   bool gameRunning = true;
   welcomeMessage();
   while (gameRunning)
   {
      showMenu();
      std::string input;
      getInput(input);
      makeSelection(input, game, gameRunning);

      while (game->isBeingPlayed())
      {
         game->showGameState();
         getInput(input);
         makeSelection(input, game, gameRunning);
         // continue game play
         game->continueGamePlay(gameRunning);
      } 
   }
   delete game;

   return EXIT_SUCCESS;
}

void welcomeMessage()
{
   std::cout << std::endl;
   std::cout << "Welcome to Qwirkle!" << std::endl;
   std::cout << "-------------------" << std::endl;
}

void showMenu()
{
   std::cout << std::endl;
   std::cout << "Menu" << std::endl;
   std::cout << "----" << std::endl;
   std::cout << "1. New Game" << std::endl;
   std::cout << "2. Load Game" << std::endl;
   std::cout << "3. Credits (Show student information)" << std::endl;
   std::cout << "4. Quit" << std::endl;
}

void getInput(std::string &input)
{
   std::cout << "> ";
   std::getline(std::cin, input);
   std::cout << std::endl;
}

void makeSelection(std::string input, Game *&game, bool &gameRunning)
{
   // NEW GAME
   if (input.compare("1") == 0 && !game->isBeingPlayed())
   {
      std::string tempName;
      std::cout << "Starting a New Game" << std::endl << std::endl;;
      std::cout << std::endl;

      // PLAYER 1 NAME INPUT
      std::cout << "Enter a name for player 1 (uppercase characters only)" << std::endl;
      getInput(tempName);
      game->addPlayer(tempName);
      std::cout << std::endl;

      // PLAYER 2 NAME INPUT
      std::cout << "Enter a name for player 2 (uppercase characters only)" << std::endl;
      getInput(tempName);
      game->addPlayer(tempName);
      std::cout << std::endl;

      // WELCOME MESSAGE
      std::cout << "Let's Play!" << std::endl;
      std::cout << std::endl;

      // START GAME
      game->startGame();
   }
   // LOAD GAME
   else if (input.compare("2") == 0)
   {
      std::cout << std::endl;
      std::string filename;
      std::cout << "Enter the filename from which load a game" << std::endl;
      getInput(filename);
      game->loadGame(filename);
   }
   
   // REPLACE TILE
   else if (input.find("replace") != std::string::npos) {
      if (game->getBag()->size() == 0) {
         std::cout << "Bag is empty. Please try again: " << std::endl;
         std::cout << std::endl;
         if (game->getPlayerCount() != 0){
            game->getPlayer(game->getCurrentPlayerID())->setRepeatTurn(true);
         }
      }
      else {
         Player* player = game->getPlayer(game->getCurrentPlayerID());
         int tileIndex = -1;
         bool tileSanity = false;
         while (!(tileSanity)) {
            std::string errorMessage = "ERROR: ";
            // IMPORT VARIABLES AS STRINGS
            input = input.erase(0, input.find(DELIMITER) + DELIMITER.length());

            // TILESTRING
            std::string tileString = input.substr(0, input.find(DELIMITER));
            // std::cout << "tileString: " << tileString << std::endl;
            input = input.erase(0, input.find(DELIMITER) + DELIMITER.length());

            // MATCH TILE INDEX AND GRAB TILE TO REPLACE
            tileIndex = player->getHand()->getIndex(tileString);
            if (0 <= tileIndex && tileIndex < HANDSIZE) {
               tileSanity = true;
            }
            else {
               errorMessage += "The specified tile does not exist in your hand. ";
               errorMessage += "Please try again: ";
               std::cout << errorMessage << std::endl;
               getInput(input);
            }
         }
         game->replaceTileInHand(tileIndex);
      }
   }

   // PLACE TILE
   else if (input.find("place") != std::string::npos && input.find("at") != std::string::npos) {

      // TODO:
      // increase input sanitisation for row&col to include incorrect types, not just incorrect values
      int score = 0;
      Player* player = game->getPlayer(game->getCurrentPlayerID());

      Tile* tile = new Tile('Z', -1);
      int tileIndex = -1;
      int row = -1;
      int col = -1;
         
      // WHILE CURRENT PLAYER HASN'T MADE A VALID PLAY
      while (score<=0) {

         // INPUT SANITSATION
         bool tileSanity = false;
         bool rowSanity = false;
         bool colSanity = false;
         std::string errorMessage = "ERROR: ";

         // WHILE INPUT IS NOT VALID
         while (!(tileSanity && rowSanity && colSanity)) {

            // INPUT SANITSATION
            tileSanity = false;
            rowSanity = false;
            colSanity = false;
            errorMessage = "ERROR: ";

            // IMPORT VARIABLES AS STRINGS
            input = input.erase(0, input.find(DELIMITER) + DELIMITER.length());

            // TILESTRING
            std::string tileString = input.substr(0, input.find(DELIMITER));
            // std::cout << "tileString: " << tileString << std::endl;
            input = input.erase(0, input.find(DELIMITER) + DELIMITER.length());
            input = input.erase(0, input.find(DELIMITER) + DELIMITER.length());

            //LOCATION STRING
            std::string locationString = input;
            // std::cout << "locationString: " << locationString <<  std::endl;

            // MATCH TILE INDEX AND GRAB TILE TO ADD TO BOARD
            tileIndex = player->getHand()->getIndex(tileString);
            // std::cout << "player->getHand()->getIndex(" << tileString << "): " << player->getHand()->getIndex(tileString) << std::endl;
            // std::cout << "tileIndex: " << tileIndex << std::endl;
            // CHECK IF TILE IS VALID
            if (0 <= tileIndex && tileIndex < HANDSIZE) {
               tileSanity = true;
               // std::cout << "tileSanity: " << tileSanity << std::endl;
               tile = player->getHand()->get(tileIndex);
            }
            else {
               errorMessage += "The specified tile does not exist in your hand. ";
            }
            // std::cout << "tile.fullName: " << tile->fullName << std::endl;

            // IMPORT ROW
            row = locationString[0] - CHARINTVAL;
            // std::cout << "row: " << row << std::endl;
            // CHECK IF ROW VALUE IS VALID
            if (0 <= row && row < BOARD_DIM) {
               rowSanity = true;
               // std::cout << "rowSanity: " << rowSanity << std::endl;
            }
            else {
               errorMessage += "The specified row is out of bounds. ";
            }

            // IMPORT COL
            std::string colString = locationString.substr(1, std::string::npos);
            // std::cout << "colString: " << colString << std::endl;
            col = std::stoi(locationString.substr(1, std::string::npos));
            // std::cout << "col: " << col << std::endl;
            // CHECK IF COLUMN VALUE IS VALID
            if (0 <= col && col < BOARD_DIM) {
               colSanity = true;
               // std::cout << "colSanity: " << colSanity << std::endl;
            }
            else {
               errorMessage += "The specified column is out of bounds. ";
            }

            // DISPLAY ERROR IF ANY INPUT IS INCORRECT
            if ((!tileSanity || !rowSanity || !colSanity)) {
               errorMessage += "Please try again: ";
               std::cout << errorMessage << std::endl;
               getInput(input);
            }
         }
         if (game->getBag()->size() == 60) {
            score++;
         }
         else if (game->getBoard()->scoreValidate(row, col, tile) > 0) {
            // game->placeTileOnBoard(tile, row, col);
            score = game->getBoard()->scoreValidate(row,col,tile);
         }
         else {
            // EXPECT PLAYER TO PLACE NEW TILE
            std::cout << "The specified location is not valid, please try again: " << std::endl;
            // std::cout << "score: " << score << std::endl;
            getInput(input);

         }

      }

      if (score >=12) {
         std::cout << "QWIRKLE!!!" << std::endl;
      }

      // PLACE TILE ON BOARD
      game->placeTileOnBoard(tile, row, col);

      // ADJUST PLAYER SCORE + HAND
      player->addScore(score);
      player->getHand()->remove(tileIndex);
      game->addTileToPlayerHand(game->getCurrentPlayerID());
      // player->addTile(game->getBag()->popTile());
   }

   // LOAD GAME
   else if (input.compare("2") == 0 && !game->isBeingPlayed())
   {
      std::cout << "Load Game selected" << std::endl;
   }

   // CREDITS
   //shows the credits 3 has been entered when the game is not being played
   else if (input.compare("3") == 0 && !game->isBeingPlayed())
   {
      game->showCredits();
   }

   // END GAME
   //ends the program if 4 has been entered when the game is not being played
   else if (input.compare("4") == 0 && !game->isBeingPlayed())
   {
      game->endGame(gameRunning);
   }
   // ends the whole program if the eof character has been pressed
   else if (std::cin.eof())
   {
      game->endGame(gameRunning);
   }
   // SAVE GAME
   else if (input.find("save") != std::string::npos)
   {
      std::string filename = input.substr(5);
      
      game->saveGame(filename);
   }

   // INVALID INPUT
   else
   {
      std::cout << "Invalid input" << std::endl;
      std::cout << std::endl;
      if (game->getPlayerCount() != 0)
      {
         game->getPlayer(game->getCurrentPlayerID())->setRepeatTurn(true);
      }
   }
}