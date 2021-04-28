#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

class Tile {
public:

   Tile(Colour colour, Shape shape);
   ~Tile();
   Tile(Tile& other);

   Colour colour;
   Shape  shape;

};

#endif // ASSIGN2_TILE_H
