#include "Prompt.h"
#include <iostream>
Prompt::Prompt()
{
}
Prompt::~Prompt()
{
}
void Prompt::welcomeMessage()
{
    std::cout << "Welcome to Qwirkle!" << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << std::endl;
}