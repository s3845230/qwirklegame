
#ifndef ASSIGN2_GAME_H
#define ASSIGN2_GAME_H

#include "Player.h"
#include "LinkedList.h"
#include "Board.h"
#include "TileBag.h"
#include <vector>

#define MAX_NUM_OF_PLAYERS 2
#define MAX_NUM_OF_TILES 72
#define SAVE_FILE_LENGTH 10
#define GAME_DIM 6

class Game
{
public:
    Game();
    ~Game();
    Player *getPlayer(unsigned int playernum);
    TileBag *getBag();
    void setBag(std::string bagAsString);
    void setCurrentPlayer(int playerId);
    int getCurrentPlayer();
    int getPlayerCount();
    Board *getBoard();
    void addPlayer(std::string name);
    void loadGame(std::string filename);
    void loadGameState(std::string fileArray[]);
    void showCredits();
    void printStudentDetails(std::string fullname, std::string stuNo, std::string email);
    void setBeingPlayed(bool playState);
    bool isBeingPlayed();
    void showGameState();
    void addTilesToBag();
    void distributeTilesToPlayers();
    void addTileToPlayerHand(int playerId);
    void placeTileInBoard(int selectedTileIndex, int row, int col);
    void replaceTileInHand(int selectedTileIndex);
    void saveGame(std::string filename);
    bool fileExists(std::string filename);
    void continueGamePlay(bool &gameRunning);
    void showGameOverMessage();
    void switchPlayer();
    void startGame();
    void endGame(bool &gameRunning);

private:
    Player *players[MAX_NUM_OF_PLAYERS];
    TileBag *bag;
    int currentPlayer;
    int playerCount;
    bool beingPlayed;
    Board *board;
};

#endif // ASSIGN2_GAME_H
