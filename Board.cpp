#include "Board.h"

#include <string>
#include <iostream>

Board::Board() {

    this->state.resize(BOARD_DIM);
    for (int i = 0; i < BOARD_DIM; i++)
    {
        this->state[i] = std::vector<Tile *>(BOARD_DIM);
        for (int j = 0; j < BOARD_DIM; j++)
        {
            this->state[i][j] = nullptr;
        }
    }
    
}

Board::~Board() {

}

bool Board::isLocationAvailable(int row, int col) {

    bool retValue = false;

    if (this->state[row][col] == nullptr) {
        retValue = true;
    }

    return retValue;
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

int Board::scoreValidate(int row, int col, Tile* newTile) {

    // BUGS:
    // REMOVE placeTile() FROM Board.cpp: IT BELONGS IN THE GAME LOGIC CLASS

    std::cout << "row: " << row << "\tcol: " << col << "\tnewTile: " << newTile->colour << newTile->shape << std::endl;

    // LOCATION VALIDATION
    if (!isLocationAvailable(row,col)) {
        std::cout << "LOCATION NOT AVAIABLE" << std::endl;
        return 0;
    }

    // VARIABLE INITIALISATION
    int score[4] = {0,0,0,0};
    int directionTravel[8] = {1,0,-1,0,0,1,0,-1};
    char directionAttribute[2];

    for (int i = 0; i < 4; i++) {

        // INITALISE LOCATION VIEWING
        int nextRow = row+directionTravel[i];
        int nextCol = col+directionTravel[4+i];

        int direction = i%2;
        Tile* tile;

        if(!isLocationAvailable(nextRow, nextCol)) {
            // CHECKING TO SEE IF FOUR IMMEDIATE NEIGHBOURS ARE VALID
            tile = this->state[nextRow][nextCol];

            if (tile->colour == newTile->colour && tile->shape == newTile->shape) {
                std::cout << "SAME TILE AS NEIGHBOUR; INVALID" << std::endl;
                return 0;
                }
            else if (tile->colour == newTile->colour) {
                directionAttribute[direction] = COLOUR;
                score[i]++;
            }
            else if (tile->shape == newTile->shape) {
                directionAttribute[direction] = SHAPE;
                score[i]++;
                }
            else {
                std::cout << "NEIGHBORMATCH else{}" << std::endl;
                return 0;
            }
            
            // CHECKING TO SEE IF EACH SEQUENCE FOLLOWING THE NEIGHBOURS ARE VALID
            while (!isLocationAvailable(nextRow, nextCol)) {
        
                tile = this->state[nextRow][nextCol];

                if ((directionAttribute[direction] == SHAPE) && (tile->shape == newTile->shape)) {score[i]++;}           
                else if ((directionAttribute[direction] == COLOUR) && (tile->colour == newTile->colour)) {score[i]++;}
                // SEQUENCE CANNOT BE CONTINUED, 0 SCORE: NOT VALID
                else {
                    std::cout << "SEQUENCEMATCH else{}" << std::endl;
                    return 0;
                }
                
                nextRow += directionTravel[i];
                nextCol += directionTravel[4+i];
            }

            // CANNOT PLACE TILE IN A SEQUENCE LONGER THAN THE QWIRKLE LENGTH (MUST BE REPEATS)
            if (((score[0] + score[2]) > QWIRKLE_LEN) || ((score[1] + score[3]) > QWIRKLE_LEN)) {
                std::cout << "SEQUENCE > QWIRKLE_LEN" << std::endl;
                return 0;
            }

            // delete tile;
        }
    }

    // ALL NEIGHBOURS ARE EMPTY (NOT VALID)
    if (score[1]+score[2]+score[3]+score[4]) {return 0;}

    placeTile(row, col, newTile);

    // CHECK FOR QWIRKLES
    for (int i = 0; i < 4; i++) {
        if (score[i] == 6) {score[i]+=6;}
    }
    return score[0]+score[1]+score[2]+score[3];
}