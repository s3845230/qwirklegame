#include "Board.h"
#include <iostream>
#include <vector>


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

    bool returnValue = false;

    if (this->state[row][col] == nullptr) {
        returnValue = true;
    }

    return returnValue;
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
    // ARRAY TO STORE THE SCORES ADDED UP IN EACH DIRECTION
    int score[4] = {0, 0, 0, 0};
    // MODIFIERS TO ADD TO COORDINATES WHEN TRAVERSING
    int directionTravel[8] = {1, 0, -1, 0, 0, 1, 0, -1};
    // ARRAY TO STORE THE ATTRIBUTE MATCHING THE SEQUENCE IN EACH DIRECTION
    char directionAttribute[2];
    
    std::vector<std::string> horizontalTiles;
    std::vector<std::string> verticalTiles;
    std::vector<std::string>* currentVector;

    // LOCATION VALIDATION
    if (!isLocationAvailable(row, col)) {
        std::cout << "isLocationAvailable() FAIL" << std::endl;
        score[0] -= ERROR_SUBTRACT;
    }

    for (int i = 0; i < 4; i++) {

        // INITALISE NEXT LOCATION
        int nextRow = row + directionTravel[i];
        int nextCol = col + directionTravel[4 + i];

        // SET DIRECTION TO 0 (VERTICAL) OR 1 (HORIZONTAL)
        int direction = i % 2;
        Tile *tile;

        // SET POINTER TO HORIZONTAL/VERTICAL VECTOR
        if (direction == 0) {
            currentVector = &verticalTiles;
        }
        if (direction == 1) {
            currentVector = &horizontalTiles;
        }


        if (isDirectionValid(nextRow, nextCol)) {
            // CHECKING TO SEE IF FOUR IMMEDIATE NEIGHBOURS ARE VALID
            if (!isLocationAvailable(nextRow, nextCol)) {
                tile = this->state[nextRow][nextCol];

                if (tile->colour == newTile->colour && tile->shape == newTile->shape) {
                    // SAME TILE AS NEIGHBOUR; INVALID
                    std::cout << "SAME TILE AS NEIGHBOUR" << std::endl;
                    score[i] -= ERROR_SUBTRACT;
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
                    // TILE DOESN'T MATCH; INVALID
                    std::cout << "TILE DOESN'T MATCH (1)" << std::endl;
                    score[i] -= ERROR_SUBTRACT;
                }

                // CHECKING TO SEE IF EACH SEQUENCE FOLLOWING THE NEIGHBOURS ARE VALID
                while (!isLocationAvailable(nextRow, nextCol) && (isDirectionValid(nextRow, nextCol))) {

                    tile = this->state[nextRow][nextCol];

                    if (tile->colour == newTile->colour && tile->shape == newTile->shape) {
                        // SAME TILE EXISTS IN SEQUENCE; INVALID
                        std::cout << "SAME TILE EXISTS IN SEQUENCE" << std::endl;
                        score[i] -= ERROR_SUBTRACT;
                    }
                    else if ((directionAttribute[direction] == SHAPE) && (tile->shape == newTile->shape)) {
                        score[i]++;
                        currentVector->push_back(tile->fullName);
                    }
                    else if ((directionAttribute[direction] == COLOUR) && (tile->colour == newTile->colour)) {
                        score[i]++;
                        currentVector->push_back(tile->fullName);
                    }
                    else {
                        // TILE DOESN'T MATCH; INVALID
                        std::cout << "TILE DOESN'T MATCH (2)" << std::endl;
                        score[i] -= ERROR_SUBTRACT;
                    }

                    nextRow += directionTravel[i];
                    nextCol += directionTravel[4 + i];

                }
            }
        }
    }


    // for (size_t i = 0; i < horizontalTiles.size(); i++) {
    //     std::cout << "horizontalTiles:" << horizontalTiles[i] << std::endl;
    // }
    // for (size_t i = 0; i < verticalTiles.size(); i++) {
    //     std::cout << "verticalTiles:" << verticalTiles[i] << std::endl;
    // }
    for (size_t i = 0; i < horizontalTiles.size(); i++) {
        for (size_t j = i+1; j < horizontalTiles.size(); j++) {
            if (horizontalTiles[i] == horizontalTiles[j] && horizontalTiles[i] == horizontalTiles[j]) {
                score[0] -= ERROR_SUBTRACT;
                std::cout << "horizontalTiles FAIL" << std::endl;
            }
        }
    }

    for (size_t i = 0; i < verticalTiles.size(); i++) {
        for (size_t j = i+1; j < verticalTiles.size(); j++) {
            if (verticalTiles[i] == verticalTiles[j] && verticalTiles[i] == verticalTiles[j]) {
                score[0] -= ERROR_SUBTRACT;
                std::cout << "verticalTiles FAIL" << std::endl;
            }
        }
    }
    // for (int i = 0; i < 4; i++) {
    //     std::cout << "Score " << i << ": " << score[i] << std::endl;
    // }

    // SCORE CORRECTION
    for (int i = 0; i < 2; i++) {
        // DON'T COUNT NEWTILE SCORE TWICE
        if (score[i] > 0 && score[i+2] > 0) {
            score[i]--;
        }
        // ADD 6 TO SCORE IF QWIRKLE
        if (score[i] + score[i+2] == 6) {
            score[i] += 6;
        }
    }

    // RETURN TOTAL SCORE FOR ALL DIRECTIONS
    return score[0] + score[1] + score[2] + score[3];
}

bool Board::isDirectionValid(int row, int col) {
    bool returnValue = false;

    if ((row >= 0 && row < 26) && (col >= 0 && col < 26)) {
        returnValue = true;
    }

    return returnValue;

}

int Board::getNumOfTilesOnBoard() {
    int returnValue = 0;

    for (int i = 0; i < BOARD_DIM; i++) {
        for (int j = 0; j < BOARD_DIM; j++) {
            if(isLocationAvailable(i, j)) {
                returnValue += 1;
            }
        } 
    }
    
    return returnValue;    
}