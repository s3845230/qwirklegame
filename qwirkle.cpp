
#include "LinkedList.h"
#include <iostream>

#define EXIT_SUCCESS 0
void welcomeMessage();
void showMenu();
void getInput(std::string &input);
void makeSelection(std::string);
int main(void)
{
   std::string input;
   getInput(input);
   makeSelection(input);

   // LinkedList *list = new LinkedList();
   // delete list;

   // std::cout << "TODO: Implement Qwirkle!" << std::endl;

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
   std::cout << std::endl;
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
      std::cout << "1 selected" << std::endl;
   }
   else if (input.compare("2") == 0)
   {
      std::cout << "2 selected" << std::endl;
   }
   else if (input.compare("3") == 0)
   {
      std::cout << "3 selected" << std::endl;
   }
   else if (input.compare("4") == 0)
   {

      std::cout << "4 selected" << std::endl;
   }