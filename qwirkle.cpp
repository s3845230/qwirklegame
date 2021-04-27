
#include "LinkedList.h"
#include "Prompt.h"
#include <iostream>

#define EXIT_SUCCESS 0

int main(void)
{
   Prompt *prompt = new Prompt();

   prompt->welcomeMessage();
   // LinkedList *list = new LinkedList();
   // delete list;

   // std::cout << "TODO: Implement Qwirkle!" << std::endl;

   return EXIT_SUCCESS;
}
