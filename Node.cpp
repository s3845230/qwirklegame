
#include "Node.h"
#include "Tile.h"

Node::Node(Tile* tile, Node* next)
{
   this->tile = tile;
   this->next = next;
}

Node::~Node() {
   
}

Node::Node(Node& other)
{
   // TODO
}
