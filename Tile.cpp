#include "Tile.h"

Tile::Tile(Colour colour, Shape shape) {
    this->colour = colour;
    this->shape = shape;
}

Tile::Tile(Tile& other) :
    colour(other.colour),
    shape(other.shape)
{}

Tile::~Tile() {

}