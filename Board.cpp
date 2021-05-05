#include "Board.h"

Board::Board() {
}

Board::~Board() {

}

void Board::placeTile(int row, int col, Tile* tile) {
    this->state[row][col] = tile;
}

Tile* Board::getTile(int row, int col) {
    return this->state[row][col];
}

std::vector<std::vector<Tile*>> Board::getState() {
    return state;
}