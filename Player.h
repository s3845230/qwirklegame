#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include <string>

#include "LinkedList.h"

class Player
{
public:
    Player(std::string name);
    ~Player();

    std::string getName();
    int getScore();
    LinkedList *getHand();
    void setScore(int score);
    void showHand();

private:
    std::string name;
    int score;
    LinkedList *hand;
};

#endif // ASSIGN2_PLAYER_H