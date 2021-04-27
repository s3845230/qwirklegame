#ifndef ASSIGN2_TILEBAG_H
#define ASSIGN2_TILEBAG_H

#include "LinkedList.h"
#include "Tile.h"

class TileBag {
    public:

        TileBag();
        ~TileBag();
        void shuffle();
        Tile* popTile();

    private:

        Tile* top;
        LinkedList tiles;
};

#endif // ASSIGN2_TILEBAG_H