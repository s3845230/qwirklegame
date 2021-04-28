#include "Board.h"

Board::Board() {
}

Board::~Board() {

}

void Board::placeTile(Tile* tile, int row, int col) {
    this->state[row][col] = tile;
}

Tile* Board::getTile(int row, int col) {
    return this->state[row][col];
}

std::vector<std::vector<Tile*>> Board::getState() {
    return state;
}