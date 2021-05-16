#ifndef ASSIGN2_BOARD_H
#define ASSIGN2_BOARD_H

#include <vector>
#include "Tile.h"

#define BOARD_DIM 26
#define QWIRKLE_LEN 6
#define COLOUR 'C'
#define SHAPE 'S'

// NUMBER TO SUBTRACT FROM SCORE TO ENSURE SCORE !>0
#define ERROR_SUBTRACT 100

class Board
{
public:
    Board();
    ~Board();

    void placeTile(Tile* tile, int row, int col);
    Tile *getTile(int row, int col);

    std::vector<std::vector<Tile *> > getState();

    int scoreValidate(int row, int col, Tile *newTile);
    bool isLocationAvailable(int row, int col);
    int validateSequence(std::vector<Tile*> currentTiles, Tile *newTile);

    void showBoard();
    std::string getStateAsString();
    void setBoard(std::string boardAsString);
    int getNumOfTilesOnBoard();

private:
    std::vector<std::vector<Tile *> > state;

    // MODIFIERS TO ADD TO COORDINATES WHEN TRAVERSING
    const int directionTravel[8] = {1, 0, -1, 0, 0, 1, 0, -1};

};

#endif // ASSIGN2_BOARD_H
