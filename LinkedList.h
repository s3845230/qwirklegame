#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   int size();
   void clear();

   void addFront(Tile* tile);
   void addBack(Tile* tile);

   Tile* getNode(int i);
   void delNode(int i);

   // returns and deletes the last node on the LinkedList
   Tile* popNode();

private:

   Node* head;

};

#endif // ASSIGN2_LINKEDLIST_H