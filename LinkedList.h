
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

template <typename T>

class LinkedList {
public:

   LinkedList();
   ~LinkedList();

   int size();
   void clear();

   void addFront(Node<T>* node);
   void addBack(Node<T>* node);

   Node<T>* getNode(int i);
   void delNode(int i);

private:

   Node<T>* head;
   
};

#endif // ASSIGN2_LINKEDLIST_H
