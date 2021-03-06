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

int Board::validateSequence(std::vector<Tile*> currentTiles) {
    // SET INITIAL SCORE TO THE LENGTH OF THE SEQUENCE
    int sequenceScore = static_cast<int>(currentTiles.size());
    int attribute = 0;
    int test;

    // RECORD WHETHER THE CURRENT SEQUENCE HAS SIMILAR SHAPES OR COLOURS
    if (currentTiles.size() > 1) {
        if (currentTiles[0]->colour == currentTiles[1]->colour) {
            attribute = 1;
        }
        else if (currentTiles[0]->shape == currentTiles[1]->shape) {
            attribute = 2;
        }
        else {
            sequenceScore -= ERROR_SUBTRACT;
        }
    }
    // ITERATE THROUGH ALL TILES IN THE HORIZONTAL AND VERTICAL SEQUENCE AND ENSURE THAT NO TILES ARE OUT OF SEQUENCE
    for (size_t i = 0; i < currentTiles.size(); i++) {
        for (size_t j = i+1; j < currentTiles.size(); j++) {
            test = 0;
            if (currentTiles[i]->colour == currentTiles[j]->colour) {
                test += 1;
            }
            if (currentTiles[i]->shape == currentTiles[j]->shape) {
                test += 2;
            }
            if (attribute != test) {
                sequenceScore -= ERROR_SUBTRACT;
            }
        }
    }

    // ADDS 1 POINT FOR THE TILE BEING PLACED IF IT MAKES A SEQUENCE
    if (sequenceScore == 1) {
        sequenceScore = 0;
    }
    // ADDS 6 POINTS FOR QWIRKLES
    if (sequenceScore == 6) {
        sequenceScore += 6;
    }
    return sequenceScore;
}

int Board::scoreValidate(int row, int col, Tile *newTile) {

    // VARIABLE INITIALISATION
    // MODIFIERS TO ADD TO COORDINATES WHEN TRAVERSING
    int directionTravel[8] = {1, 0, -1, 0, 0, 1, 0, -1};
    int score = 0;
    
    // VECTORS TO HOLD THE VERTICAL AND HORIZONTAL TILE SEQUENCES AROUND THE TARGET LOCATION
    std::vector<Tile*> horizontalTiles;
    std::vector<Tile*> verticalTiles;
    std::vector<Tile*>* currentVector;

    // ADD NEW TILE TO BOTH SEQUENCE VECTORS
    verticalTiles.push_back(newTile);
    horizontalTiles.push_back(newTile);

    // LOCATION VALIDATION
    
    
    if (this->state[row][col] != nullptr) {
        score -= ERROR_SUBTRACT;
    }
    else if (placeableLocation(row, col) == false) {
        score -= ERROR_SUBTRACT;
    }
    else {
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

            // CREATE SEQUENCES SURROUNDING TARGET LOCATION
            for (int j = 0; j < 7; j++) {
                if (nextRow < static_cast<int>(state.size()) && nextRow > -1 && nextCol < static_cast<int>(state[1].size()) && nextCol > -1) {
                    if (this->state[nextRow][nextCol] != nullptr) {
                        tile = this->state[nextRow][nextCol];
                        nextRow += directionTravel[i];
                        nextCol += directionTravel[4 + i];
                        // ADD THE TILE TO THE RELEVANT TILE SEQUENCE
                        currentVector->push_back(tile);
                    }
                // ELSES TO EXIT THE LOOP
                    else {
                        j = 7;}
                }
                else {
                    j = 7;}
            }
        }
    }

    // ADDING SCORE
    score += validateSequence(verticalTiles);
    score += validateSequence(horizontalTiles);
    return score;
}

// CHECK WHETHER LOCATION IS TILE-ADJACENT
bool Board::placeableLocation(int row, int col) {
    bool northEmpty = false;
    bool eastEmpty = false;
    bool southEmpty = false;
    bool westEmpty = false;
    
    // BORDER CHECK
    if (row == 0) {
        northEmpty = true;
    }
    else {
        // CHECK IF LOCATION IS EMPTY
        if (this->state[row-1][col] == nullptr) {
            northEmpty = true;
        }
    }
    // REST ARE THE SAME AS ABOVE FOR OTHER DIRECTIONS
    if (row == static_cast<int>(state.size())-1) {
        southEmpty = true;
    }
    else {
        if (this->state[row+1][col] == nullptr) {
            southEmpty = true;
        }
    }
    if (col == static_cast<int>(state[1].size())) {
        eastEmpty = true;
    }
    else {
        if (this->state[row][col+1] == nullptr) {
            eastEmpty = true;
        }
    }
    if (col == 0) {
        westEmpty = true;
    }
    else {
        if (this->state[row][col-1] == nullptr) {
            westEmpty = true;
        }
    }
    if (northEmpty && westEmpty && eastEmpty && southEmpty) {
        return false;
        // ONLY RETURN FALSE IF ALL ADJACENT TILES ARE EMPTY OR BORDERS
    }
    else {
        return true;
    }
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

int Board::findBestLocation(int &bestRow, int &bestCol, Tile *newTile) {
    int bestScore = 0;
    int currentScore = 0;
    bestRow = -1;
    bestCol = -1;
    // ITERATE THROUGH ALL ROWS
    for (int row = 0; row < BOARD_DIM; row++) {
        // ITERATE THROUGH ALL COLUMNS
        for (int col = 0; col < BOARD_DIM; col++) {
            // CHECK SCORE AT CURRENT LOCATION WITH GIVEN TILE
            currentScore = scoreValidate(row, col, newTile);
            if (currentScore > bestScore) {
                // UPDATE IF BETTER
                bestScore = currentScore;
                bestRow = row;
                bestCol = col;
            }
        }
    }
    return bestScore;
}