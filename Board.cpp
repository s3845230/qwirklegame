#include "Board.h"
#include <iostream>

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
Board::~Board()
{
}
void Board::showBoard()
{
    char characters = 65;

    for (int i = 0; i < BOARD_DIM; i++)
    {
        if (i == 0)
        {
            for (int k = 0; k < BOARD_DIM; k++)
            {
                if (k == 0)
                {
                    std::cout << "   ";
                }
                if (k <= 9)
                {
                    std::cout << k << "  ";
                }
                else
                {
                    std::cout << k << " ";
                }
            }
            std::cout << std::endl;
            std::cout << "  -------------------------------------------------------------------------------" << std::endl;
        }
        for (int j = 0; j < BOARD_DIM; j++)
        {
            if (j == 0)
            {
                std::cout << characters << " |";
                characters++;
            }
            if (this->state[i][j] == nullptr)
            {
                std::cout << "  |";
            }
            else
            {
                std::cout << this->state[i][j]->colour << this->state[i][j]->shape << "|";
            }
        }
        std::cout << std::endl;
    }
}
bool Board::isLocationAvailable(int row, int col)
{

    bool retValue = false;

    if (this->state[row][col] == nullptr)
    {
        retValue = true;
    }

    return retValue;
}

void Board::placeTile(Tile *tile, int row, int col)
{
    this->state[row][col] = new Tile(*tile);
}
std::string Board::getStateAsString()
{
    std::string retValue = "";
    char characters = 65;

    for (int i = 0; i < BOARD_DIM; i++)
    {
        for (int j = 0; j < BOARD_DIM; j++)
        {
            if (this->state[i][j] != nullptr)
            {
                if (retValue.compare("") == 0)
                {
                    retValue += this->state[i][j]->fullName + "@" + char(characters + i) + std::to_string(j);
                }
                else
                {
                    retValue += ", " + this->state[i][j]->fullName + "@" + char(characters + i) + std::to_string(j);
                }
            }
        }
    }

    return retValue;
}
void Board::setBoard(std::string boardAsString)
{

    for (int i = 0; i < boardAsString.length(); i += 7)
    {
        std::string tile = boardAsString.substr(i, 2);
        char colour = tile[0];
        int shape = stoi(tile.substr(1));

        char rowInChar = boardAsString[i + 3];
        int row = rowInChar - 65;
        int col;
        // std::cout << "i = " << i << " = " << tile << std::endl;
        // std::cout << "i + 3 = " << i << " = " << boardAsString[i + 3] << std::endl;
        // std::cout << "i + 4 = " << i << " = " << boardAsString[i + 4] << std::endl;

        if (boardAsString.substr(i + 5, 1).compare(",") == 0 || (i + 5) == boardAsString.length())
        {
            col = stoi(boardAsString.substr(i + 4, 1));
            // std::cout << "comma found or end of line" << std::endl;
        }
        else
        {
            // std::cout << "i + 5 = " << i << " = " << boardAsString[i + 5] << std::endl;
            col = stoi(boardAsString.substr(i + 4, 2));
            i++;
        }
        Tile *newTile = new Tile(colour, shape);
        this->placeTile(newTile, row, col);
    }
}