#ifndef ASSIGN2_PLAYER_H
#define ASSIGN2_PLAYER_H

#include <string>
#include "Tile.h"
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
    bool getRepeatTurn();
    void setRepeatTurn(bool repeatTurn);
    void addTile(Tile *tile);
    void showHand();
    std::string getHandAsString();

private:
    std::string name;
    int score;
    bool repeatTurn;
    LinkedList *hand;
};

#endif // ASSIGN2_PLAYER_H