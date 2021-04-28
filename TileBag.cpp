#include <stdlib.h>


#include "TileBag.h"

#define TILE_VARIATION 6 // number of possible values each attribute of the Tile can have

TileBag::TileBag() {
    // initalise with standard set of tiles
    char colours[TILE_VARIATION] = {'R', 'O', 'Y', 'G', 'B', 'P'};
    int shapes[TILE_VARIATION] = {1, 2, 3, 4, 5, 6};

    // adds two of each tile
    for (int i = 0; i < TILE_VARIATION; i++) {
        for (int j = 0; j < TILE_VARIATION; j++) {
            this->tiles->addBack(new Node(new Tile(colours[i], shapes[j]), nullptr));
            this->tiles->addBack(new Node(new Tile(colours[i], shapes[j]), nullptr));
        }
    }

}

TileBag::~TileBag() {
    delete topTile;
    delete tiles;
}

void TileBag::shuffle() {

    // Create new empty LinkedList
    LinkedList* shuffleBag = new LinkedList();

    // for each tile in TileBag.tiles, select a random one and place it in shuffleBag
    for (int i = 0; i < this->tiles->size(); i++) {
        int randomIndex = rand() % this->tiles->size() + 1;
        shuffleBag->addBack(this->tiles->getNode(randomIndex));
        this->tiles->delNode(randomIndex);
    }

    // empty TileBag.tiles
    this->tiles->clear();
    // make TileBag.tiles equal to shuffleBag
    this->tiles = shuffleBag;
    
    // free memory used for shuffleBag;
    delete shuffleBag;
}

Tile* TileBag::popTile() {

    this->topTile = this->tiles->popNode()->tile;
    return this->topTile;

}


