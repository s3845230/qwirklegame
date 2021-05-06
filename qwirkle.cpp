
#include "LinkedList.h"
#include "TileBag.h"
#include <iostream>
#include "Game.h"
#include "TileBag.h"
#include "Board.h"

#define EXIT_SUCCESS 0
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
   if (input.compare("1") == 0 && !game->isBeingPlayed())
   {
      std::string tempName;
      std::cout << "Starting a New Game" << std::endl;
      std::cout << std::endl;
      std::cout << "Enter a name for player 1 (uppercase characters only)" << std::endl;
      getInput(tempName);
      game->addPlayer(tempName);
      std::cout << std::endl;
      std::cout << "Enter a name for player 2 (uppercase characters only)" << std::endl;
      getInput(tempName);
      game->addPlayer(tempName);
      std::cout << std::endl;
      std::cout << "Let's Play!" << std::endl;
      std::cout << std::endl;

      game->startGame();
   }
   else if (input.compare("2") == 0 && !game->isBeingPlayed())
   {
      std::cout << "Load Game selected" << std::endl;
   }
   //shows the credits 3 has been entered when the game is not being played
   else if (input.compare("3") == 0 && !game->isBeingPlayed())
   {
      game->showCredits();
   }
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
   else
   {
      std::cout << "Invalid input" << std::endl;
      std::cout << std::endl;
      if (game->getPlayerCount() != 0)
      {
         game->getPlayer(game->getCurrentPlayer())->setRepeatTurn(true);
      }
   }
}