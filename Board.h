#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include <vector>
#include "Tile.h"

#define BOARD_DIM 26

class Board
{
public:
    Board();
    ~Board();
    void placeTile(Tile *tile, int row, int col);
    Tile *getTile(int row, int col);
    std::vector<std::vector<Tile *> > getState();
    void showBoard();
    bool isLocationAvailable(int row, int col);

    std::string getStateAsString();
    void setBoard(std::string boardAsString);

private:
    std::vector<std::vector<Tile *> > state;
};

#endif // ASSIGN2_BOARD_H