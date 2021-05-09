
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList
{
public:
   LinkedList();
   LinkedList(LinkedList &other);
   ~LinkedList();

   int size();

   Tile *get(int index);

   int getIndex(std::string tileString); // returns index of Tile pointer

   std::string getContentAsString();
   void add_front(Tile *data);
   void add_back(Tile *data);

   //Contract: Elements should exist in the list to be deleted.
   void remove_front();
   void remove_back();

   void remove(int index);

   void clear();
   Tile *popNode();

private:
   Node *head;
};

#endif // ASSIGN2_LINKEDLIST_H
