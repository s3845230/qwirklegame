
#include "LinkedList.h"
#include <iostream>

#include "TileBag.h"

#define EXIT_SUCCESS 0
void welcomeMessage();
void showMenu();
void getInput(std::string &input);
void makeSelection(std::string);

bool inputCorrect = false;

int main(void)
{  
   std::string input;
   welcomeMessage();
   showMenu();
   while (!inputCorrect)
   {
      getInput(input);
      makeSelection(input);
   }

   // LinkedList *list = new LinkedList();
   // delete list;

   // std::cout << "TODO: Implement Qwirkle!" << std::endl;

   // TileBag* tilebag = new TileBag();
   // std::cout << tilebag << std::endl;

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
   if ((input == "1") || (input == "2") || (input == "3") || (input == "4"))
   {
      if (input.compare("1") == 0)
      {
         std::cout << "New Game selected" << std::endl;
         inputCorrect = true;
      }
      else if (input.compare("2") == 0)
      {
         std::cout << "Load Game selected" << std::endl;
         inputCorrect = true;
      }
      else if (input.compare("3") == 0)
      {
         std::cout << "Name: Yonas Sisay" << std::endl;
         std::cout << "Student ID: s3659939" << std::endl;
         std::cout << "Email: s3659939@student.rmit.edu.au" << std::endl;
         std::cout << "" << std::endl;
         std::cout << "Name: Lachlan Kris Stavrevski" << std::endl;
         std::cout << "Student ID: s3843294" << std::endl;
         std::cout << "Email: s3843294@student.rmit.edu.au" << std::endl;
         std::cout << "" << std::endl;
         std::cout << "Name: Roman O'Brien" << std::endl;
         std::cout << "Student ID: s3845295" << std::endl;
         std::cout << "Email: s3845295@student.rmit.edu.au" << std::endl;
         std::cout << "" << std::endl;
         std::cout << "Name: David Morrin" << std::endl;
         std::cout << "Student ID: s3845295" << std::endl;
         std::cout << "Email: s3845230@student.rmit.edu.au" << std::endl;
         showMenu();
      }
      else if (input.compare("4") == 0)
      {
         std::cout << "" << std::endl;
         std::cout << "Goodbye" << std::endl;
         inputCorrect = true;
      }  
   }
   else
   {
      std::cout << "Please enter a valid option" << std::endl;
   }
}