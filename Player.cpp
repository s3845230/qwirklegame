
#include <iostream>
#include "Player.h"

Player::Player(std::string name)
{
    this->name = name;
}

Player::~Player()
{
    delete hand;
}

std::string Player::getName()
{
    return this->name;
}

int Player::getScore()
{
    return this->score;
}

LinkedList *Player::getHand()
{
    return this->hand;
}

void Player::setScore(int score)
{
    this->score = score;
}

void Player::showHand()
{
    for (int i = 0; i < this->hand->size(); i++)
    {
        std::cout << this->hand->getNode(i)->colour << this->hand->getNode(i)->shape;
        if (i < this->hand->size() - 1)
        {
            std::cout << ",";
        }
    }
    std::cout << std::endl;
}