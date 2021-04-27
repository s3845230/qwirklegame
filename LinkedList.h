
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   int size();
   void clear();

   void addFront(Node* node);
   void addBack(Node* node);

   Node* getNode(int i);
   void delNode(int i);

private:

   Node* head;

};

#endif // ASSIGN2_LINKEDLIST_H
