#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include <vector>
#include "Tile.h"

#define BOARD_DIM 26
#define QWIRKLE_LEN 6
#define COLOUR 'C'
#define SHAPE 'S'

class Board
{
public:
    Board();
    ~Board();
    
    // LET FIRST MOVE BE ANY PLAY
    bool firstMoveTaken;

    void placeTile(Tile* tile, int row, int col);
    Tile *getTile(int row, int col);

    std::vector<std::vector<Tile *> > getState();

    int scoreValidate(int row, int col, Tile *newTile);
    bool isLocationAvailable(int row, int col);
    void showBoard();
    std::string getStateAsString();
    void setBoard(std::string boardAsString);
    int getNumOfTilesOnBoard();

    bool isDirectionValid(int row, int col);

private:
    std::vector<std::vector<Tile *> > state;

};

#endif // ASSIGN2_BOARD_H
