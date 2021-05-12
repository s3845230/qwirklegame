#include "Board.h"
#include <iostream>

#define ERROR 100

Board::Board()
{
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

void Board::showBoard() {
    char characters = 65;

    for (int i = 0; i < BOARD_DIM; i++) {
        if (i == 0) {
            for (int k = 0; k < BOARD_DIM; k++) {
                if (k == 0) {
                    std::cout << "   ";
                }
                if (k <= 9) {
                    std::cout << k << "  ";
                }
                else {
                    std::cout << k << " ";
                }
            }
            std::cout << std::endl;
            std::cout << "  -------------------------------------------------------------------------------" << std::endl;
        }
        for (int j = 0; j < BOARD_DIM; j++) {
            if (j == 0) {
                std::cout << characters << " |";
                characters++;
            }
            if (this->state[i][j] == nullptr) {
                std::cout << "  |";
            }
            else {
                std::cout << this->state[i][j]->colour << this->state[i][j]->shape << "|";
            }
        }

        std::cout << std::endl;
    }
}

bool Board::isLocationAvailable(int row, int col) {

    bool retValue = false;

    if (this->state[row][col] == nullptr) {
        retValue = true;
    }

    return retValue;
}

void Board::placeTile(Tile* tile, int row, int col) {
    this->state[row][col] = new Tile(*tile);
}

std::string Board::getStateAsString() {
    std::string stateAsString = "";
    char characters = 65; // what does this magic number do?

    for (int i = 0; i < BOARD_DIM; i++) {
        for (int j = 0; j < BOARD_DIM; j++) {
            if (this->state[i][j] != nullptr) {
                if (stateAsString.compare("") == 0) {
                    stateAsString += this->state[i][j]->fullName + "@" + char(characters + i) + std::to_string(j);
                }
                else {
                    stateAsString += ", " + this->state[i][j]->fullName + "@" + char(characters + i) + std::to_string(j);
                }
            }
        }
    }

    return stateAsString;
}

void Board::setBoard(std::string boardAsString) {

    for (int i = 0; i < int(boardAsString.length()); i += 7) {
        std::string tile = boardAsString.substr(i, 2);
        char colour = tile[0];
        int shape = stoi(tile.substr(1));

        char rowInChar = boardAsString[i + 3];
        int row = rowInChar - 65;
        int col;
        // std::cout << "i = " << i << " = " << tile << std::endl;
        // std::cout << "i + 3 = " << i << " = " << boardAsString[i + 3] << std::endl;
        // std::cout << "i + 4 = " << i << " = " << boardAsString[i + 4] << std::endl;

        if (boardAsString.substr(i + 5, 1).compare(",") == 0 || (i + 5) == int(boardAsString.length())) {
            col = stoi(boardAsString.substr(i + 4, 1));
            // std::cout << "comma found or end of line" << std::endl;
        }
        else {
            // std::cout << "i + 5 = " << i << " = " << boardAsString[i + 5] << std::endl;
            col = stoi(boardAsString.substr(i + 4, 2));
            i++;
        }

        Tile *newTile = new Tile(colour, shape);
        this->placeTile(newTile, row, col);
    }
}

std::vector<std::vector<Tile *> > Board::getState() {
    return state;
}

int Board::scoreValidate(int row, int col, Tile *newTile) {

    // VARIABLE INITIALISATION
    int score[4] = {0, 0, 0, 0};
    // MODIFIERS TO ADD TO COORDINATES WHEN TRAVERSING
    int directionTravel[8] = {1, 0, -1, 0, 0, 1, 0, -1};
    char directionAttribute[2];

    // LOCATION VALIDATION
    if (!isLocationAvailable(row, col)) {
        score[0] -= ERROR;
    }

    for (int i = 0; i < 4; i++) {

        // INITALISE NEXT LOCATION
        int nextRow = row + directionTravel[i];
        int nextCol = col + directionTravel[4 + i];

        int direction = i % 2;
        Tile *tile;


        if (isDirectionValid(nextRow, nextCol)) {
            if (!isLocationAvailable(nextRow, nextCol)) {
                // CHECKING TO SEE IF FOUR IMMEDIATE NEIGHBOURS ARE VALID
                tile = this->state[nextRow][nextCol];

                if (tile->colour == newTile->colour && tile->shape == newTile->shape) {
                    // SAME TILE AS NEIGHBOUR; INVALID
                    score[i] -= ERROR;
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
                    score[i] -= ERROR;
                }

                // CHECKING TO SEE IF EACH SEQUENCE FOLLOWING THE NEIGHBOURS ARE VALID
                while (!isLocationAvailable(nextRow, nextCol) && (isDirectionValid(nextRow, nextCol))) {

                    tile = this->state[nextRow][nextCol];

                    if (tile->colour == newTile->colour && tile->shape == newTile->shape) {
                        // SAME TILE EXISTS IN SEQUENCE; INVALID
                        score[i] -= ERROR;
                    }
                    else if ((directionAttribute[direction] == SHAPE) && (tile->shape == newTile->shape)) {
                        score[i]++;
                    }
                    else if ((directionAttribute[direction] == COLOUR) && (tile->colour == newTile->colour)) {
                        score[i]++;
                    }

                    else {
                        // SEQUENCE CANNOT BE CONTINUED
                        score[i] -= ERROR;
                    }

                    nextRow += directionTravel[i];
                    nextCol += directionTravel[4 + i];

                }
            }
        }
    }
        

    // SCORE CORRECTION
    for (int i = 0; i < 2; i++) {
        // DON'T COUNT NEWTILE SCORE TWICE
        if (score[i] + score[i+2] > 6) {
            score[i]--;
        }
        // ADD 6 TO SCORE IF QWIRKLE
        if (score[i] + score[i+2] == 6) {
            score[i] += 6;
        }
    }

    return score[0] + score[1] + score[2] + score[3];
}

bool Board::isDirectionValid(int row, int col) {
    bool retValue = false;

    if ((row >= 0 && row < 26) && (col >= 0 && col < 26)) {
        retValue = true;
    }

    return retValue;

}

int Board::getNumOfTilesOnBoard()
{
    int retVal = 0;

    for (int i = 0; i < BOARD_DIM; i++)
    {
        for (int j = 0; j < BOARD_DIM; j++)
        {
            if(isLocationAvailable(i, j))
            {
                retVal += 1;
            }
        } 
    }
    return retVal;    
}