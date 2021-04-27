
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"

template <typename T>

class LinkedList {
public:

   LinkedList(T type);
   ~LinkedList();

   int size();
   void clear();

   void addFront(Node<type>* node);
   void addBack(Node<type>* node);

   Node<type>* getNode(int i);
   void delNode(int i);

private:
   T type;
   Node<type>* head;

};

#endif // ASSIGN2_LINKEDLIST_H
