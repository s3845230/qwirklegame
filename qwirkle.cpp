
#include "LinkedList.h"
#include <iostream>
#include "Game.h"
#include "TileBag.h"

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
}

void makeSelection(std::string input, Game *&game, bool &gameRunning)
{
   if (input.compare("1") == 0)
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
   else if (input.compare("2") == 0)
   {
      std::cout << "Load Game selected" << std::endl;
   }
   else if (input.compare("3") == 0)
   {
      std::cout << "Credits selected" << std::endl;
   }
   else if (input.compare("4") == 0)
   {

      std::cout << "Quit selected" << std::endl;
   }
}