
#include "LinkedList.h"
#include "Prompt.h"
#include <iostream>

#define EXIT_SUCCESS 0
void getInput(std::string &input);
int main(void)
{

   // LinkedList *list = new LinkedList();
   // delete list;

   // std::cout << "TODO: Implement Qwirkle!" << std::endl;

   return EXIT_SUCCESS;
}
void getInput(std::string &input)
{
   std::cout << "> ";
   std::getline(std::cin, input);
}