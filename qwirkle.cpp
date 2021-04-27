
#include "LinkedList.h"

#include <iostream>

#define EXIT_SUCCESS    0

void welcomeMessage();
void showMenu();

int main(void) {

   welcomeMessage();
   showMenu();

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