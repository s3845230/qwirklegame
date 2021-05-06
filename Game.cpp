#include <iostream>
#include "Game.h"
#include "TileCodes.h"
#include <random>
#include <fstream>
#include <string>

Game::Game()
{
    this->bag = new TileBag();
    this->board = new Board();
    this->setBeingPlayed(false);
    this->currentPlayer = 0;
    this->playerCount = 0;
}

Game::~Game()
{
    delete this->bag;
    delete this->board;
    for (int i = 0; i < this->getPlayerCount(); i++)
    {
        delete this->players[i];
    }
}
void Game::addPlayer(std::string name)
{
    this->playerCount++;
    this->players[this->playerCount - 1] = new Player(name);
}
Player *Game::getPlayer(unsigned int playernum)
{
    return this->players[playernum];
}
TileBag *Game::getBag()
{
    return this->bag;
}
void Game::setBag(std::string bagAsString)
{
    // TODO
}
void Game::setCurrentPlayer(int playerId)
{
    this->currentPlayer = playerId;
}
int Game::getCurrentPlayer()
{
    return this->currentPlayer;
}
int Game::getPlayerCount()
{
    return this->playerCount;
}
Board *Game::getBoard()
{
    return this->board;
}
void Game::loadGame(std::string filename)
{
    //TODO
}
void Game::loadGameState(std::string fileArray[])
{
    //TODO
}
void Game::showCredits()
{
    std::cout << "----------------------------------" << std::endl;
    this->printStudentDetails("Yonas Sisay", "s3659939", "s3659939@student.rmit.edu.au");
    this->printStudentDetails("Roman O'Brien", "s3845295", "s3845295@student.rmit.edu.au");
    this->printStudentDetails("David Morrin", "s3845230", "s3845230@student.rmit.edu.au");
    this->printStudentDetails("Lachlan Stavrevski", "s3843294", "s3843294@student.rmit.edu.au");
    std::cout << "----------------------------------" << std::endl;
    std::cout << std::endl;
}
void Game::printStudentDetails(std::string fullname, std::string stuNo, std::string email)
{
    std::cout << "Name: " << fullname << std::endl;
    std::cout << "Student ID: " << stuNo << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << std::endl;
}

void Game::setBeingPlayed(bool playState)
{
    this->beingPlayed = playState;
}
bool Game::isBeingPlayed()
{
    return this->beingPlayed;
}
void Game::showGameState()
{
    std::cout << this->getPlayer(this->getCurrentPlayer())->getName() << ", it's your turn" << std::endl;
    for (int i = 0; i < this->getPlayerCount(); i++)
    {
        std::cout << "Score for " << this->getPlayer(i)->getName() << ": " << this->getPlayer(i)->getScore() << std::endl;
    }

    this->board->showBoard();

    std::cout << std::endl;
    std::cout << "Your hand is" << std::endl;
    this->getPlayer(this->getCurrentPlayer())->showHand();
}

void Game::addTilesToBag()
{
    // TODO
    this->bag->shuffle();
}

void Game::distributeTilesToPlayers()
{
    for (int i = 0; i < this->getPlayerCount(); i++)
    {
        for (int j = 0; j < GAME_DIM; j++)
        {
            this->addTileToPlayerHand(i);
        }
    }
}
void Game::addTileToPlayerHand(int playerId)
{
    this->getPlayer(playerId)->add(this->bag->popTile());
}
void Game::placeTileInBoard(int selectedTileIndex, int row, int col)
{
    // TODO
}

void Game::replaceTileInHand(int selectedTileIndex)
{
    // TODO
}
void Game::saveGame(std::string filename)
{
    // TODO
}
bool Game::fileExists(std::string fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}
void Game::continueGamePlay(bool &gameRunning)
{
    bool playerHandEmpty = false;
    for (int i = 0; i < this->getPlayerCount(); i++)
    {
        if (this->getPlayer(i)->getHandAsString().compare("") == 0)
        {
            playerHandEmpty = true;
        }
    }
    if (this->getBag()->size() == 0 && playerHandEmpty)
    {
        // show game over message
        //end game
    }
    else
    {
        this->switchPlayer();
    }
}
void Game::showGameOverMessage()
{
    // TODO
}
void Game::switchPlayer()
{

    //if the player is not repeating their turn then switch players else remain the same
    if (!this->getPlayer(this->getCurrentPlayer())->getRepeatTurn())
    {
        //if the current player is the last person on the list, make current player equal the first player
        //else move on to the next player in the game
        if (this->getCurrentPlayer() == this->getPlayerCount() - 1)
        {
            this->setCurrentPlayer(0);
        }
        else
        {
            this->setCurrentPlayer(this->getCurrentPlayer() + 1);
        }
    }
    else
    {
        this->getPlayer(this->getCurrentPlayer())->setRepeatTurn(false);
    }
}
void Game::startGame()
{
    this->setBeingPlayed(true);

    this->addTilesToBag();
    this->distributeTilesToPlayers();
}
void Game::endGame(bool &gameRunning)
{
    std::cout << std::endl;
    std::cout << "Goodbye" << std::endl;
    std::cout << std::endl;
    this->setBeingPlayed(false);
    gameRunning = false;
}