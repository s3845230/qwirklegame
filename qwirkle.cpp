
#include "LinkedList.h"
#include <iostream>

#include "TileBag.h"
#include "Board.h"

#define EXIT_SUCCESS 0
void welcomeMessage();
void showMenu();
void getInput(std::string &input);
void makeSelection(std::string);
int main(void)
{
   // std::string input;
   // welcomeMessage();
   // showMenu();
   // getInput(input);
   // makeSelection(input);

   // LinkedList *list = new LinkedList();
   // delete list;

   // std::cout << "TODO: Implement Qwirkle!" << std::endl;

   // TileBag* tilebag = new TileBag();
   // std::cout << tilebag << std::endl;

   Board* board = new Board();
   std::cout << board << std::endl;
   

   std::cout << board->scoreValidate(1,1, new Tile('R', 1)) << std::endl;
   std::cout << board->scoreValidate(1,2, new Tile('R', 2)) << std::endl;
   std::cout << board->scoreValidate(1,3, new Tile('R', 3)) << std::endl;
   std::cout << board->scoreValidate(1,4, new Tile('R', 4)) << std::endl;
   std::cout << board->scoreValidate(1,5, new Tile('R', 5)) << std::endl;
   std::cout << board->scoreValidate(1,6, new Tile('R', 6)) << std::endl;
   std::cout << board->scoreValidate(1,7, new Tile('R', 7)) << std::endl;
   std::cout << board->scoreValidate(2,6, new Tile('R', 5)) << std::endl;
   std::cout << board->scoreValidate(2,5, new Tile('G', 5)) << std::endl;


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

void makeSelection(std::string input)
{
   if (input.compare("1") == 0)
   {
      std::cout << "New Game selected" << std::endl;
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