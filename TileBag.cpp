
#include "TileBag.h"

TileBag::TileBag() {
    // initalise with standard set of tiles

}

TileBag::~TileBag() {

}

void TileBag::shuffle() {

}

Tile* TileBag::popTile() {

    // set top tile
    this->top = this->tiles.getNode(this->tiles.size()-1)->tile;
    return top;

}


