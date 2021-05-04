#include <iostream>
#include "Game.h"
#include "TileCodes.h"
#include <random>
#include <fstream>
#include <string>

Game::Game()
{
    this->bag = new LinkedList();
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
LinkedList *Game::getBag()
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
    // TODO
}

void Game::addTilesToBag()
{
    // TODO
}

void Game::distributeTilesToPlayers()
{
    // TODO
}
void Game::addTileToPlayerHand(int playerId)
{
    // TODO
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
    // TODO
}
void Game::showGameOverMessage()
{
    // TODO
}
void Game::switchPlayer()
{

    // TODO
}
void Game::startGame()
{
    this->setBeingPlayed(true);
    this->board = new Board();
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