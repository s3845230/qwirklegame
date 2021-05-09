
#include <iostream>
#include "Player.h"

Player::Player(std::string name)
{
    this->name = name;
    this->score = 0;
    this->repeatTurn = false;
    this->hand = new LinkedList();
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
bool Player::getRepeatTurn()
{
    return this->repeatTurn;
}
void Player::setRepeatTurn(bool repeatTurn)
{
    this->repeatTurn = repeatTurn;
}

LinkedList *Player::getHand()
{
    return this->hand;
}

void Player::setScore(int score)
{
    this->score = score;
}
void Player::addScore(int score) {
    this->score+=score;
}
void Player::addTile(Tile *tile)
{
    this->hand->add_back(tile);
}

void Player::showHand()
{
    for (int i = 0; i < this->hand->size(); i++)
    {
        std::cout << this->hand->get(i)->colour << this->hand->get(i)->shape;
        if (i < this->hand->size() - 1)
        {
            std::cout << ",";
        }
    }
    std::cout << std::endl;
}
std::string Player::getHandAsString()
{
    return this->hand->getContentAsString();
}