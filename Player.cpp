
#include <string>
#include "Player.h"

Player::Player(std::string name) {
    this->name = name;
}

Player::~Player() {
    delete hand;
}

std::string Player::getName() {
    return this->name;
}

int Player::getScore() {
    return this->score;
}

LinkedList* Player::getHand() {
    return this->hand;
}

void Player::setScore(int score) {
    this->score = score;
}