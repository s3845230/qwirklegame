#include <stdlib.h>
#include "Game.h"
#include "TileCodes.h"
#include <random>
#include "TileBag.h"

#define TILE_VARIATION 6 // number of possible values each attribute of the Tile can have

TileBag::TileBag()
{
    // initalise with standard set of tiles
    this->tiles = new LinkedList();
    char colours[TILE_VARIATION] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
    int shapes[TILE_VARIATION] = {CIRCLE, STAR_4, DIAMOND, SQUARE, STAR_6, CLOVER};

    // adds two of each tile
    for (int i = 0; i < TILE_VARIATION; i++)
    {
        for (int j = 0; j < TILE_VARIATION; j++)
        {
            this->tiles->add_back(new Tile(colours[i], shapes[j]));
            this->tiles->add_back(new Tile(colours[i], shapes[j]));
        }
    }
}

TileBag::~TileBag()
{
    delete topTile;
    delete tiles;
}

void TileBag::shuffle()
{

    // Create new empty LinkedList
    LinkedList *shuffleBag = new LinkedList();

    //Randomise using Time as rand seed
    while (this->tiles->size() > 0)
    {
        std::random_device engine;
        std::uniform_int_distribution<int> uniform_dist(0, this->tiles->size() - 1);

        int randomIndex = uniform_dist(engine);
        shuffleBag->add_back(this->tiles->get(randomIndex));
        // std::cout << "size of linkedlist " << this->tiles->size() << " rand num :" << randomIndex << std::endl;
        this->tiles->remove(randomIndex);
    }

    // Randomise using predictable seed
    // while (this->tiles->size() > 0)
    // {
    //     int randomIndex = rand() % this->tiles->size();
    //     shuffleBag->add_back(this->tiles->get(randomIndex));
    //     std::cout << "size of linkedlist " << this->tiles->size() << " rand num :" << randomIndex << std::endl;
    //     this->tiles->remove(randomIndex);
    // }

    // empty TileBag.tiles
    this->tiles->clear();
    // make TileBag.tiles equal to shuffleBag
    this->tiles = new LinkedList(*shuffleBag);

    // free memory used for shuffleBag
    delete shuffleBag;
}

Tile *TileBag::popTile()
{
    this->topTile = new Tile(*this->tiles->get(0));
    this->tiles->remove_front();

    return this->topTile;
}

int TileBag::size()
{
    return this->tiles->size();
}

void TileBag::addTile(Tile *data)
{
    tiles->add_back(data);
}

std::string TileBag::getBagAsString()
{
   std::string returnString = "";
   for (int i = 0; i < this->size(); i++)
   {
      returnString += this->tiles->get(i)->fullName;
      if (i < this->size() - 1)
      {
         returnString += ",";
      }
   }

   return returnString;
}

void TileBag::clearBag()
{
    tiles->clear();
}