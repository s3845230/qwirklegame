#include "LinkedList.h"
#include <stdexcept>
#include <iostream>

LinkedList::LinkedList()
{
   head = nullptr;
}
LinkedList::~LinkedList()
{
   Node *previous = head;
   Node *current = head;
   while (current->next != nullptr)
   {
      current = current->next;
      delete previous;
      previous = current;
   }
   delete current;
}
int LinkedList::size()
{
   int count = 0;
   Node *current = head;
   while (current->next != nullptr)
   {
      count++;
      current = current->next;
   }
   return count;
}
void LinkedList::clear()
{
   if (head->next != nullptr)
   {
      Node *current = head->next;
      Node *previous = current;
      while (current->next != nullptr)
      {
         current = current->next;
         delete previous;
         previous = current;
      }
      delete current;
      head->next = nullptr;
   }
}
Tile *LinkedList::getNode(int i)
{
   if (i < 0)
   {
      throw std::invalid_argument("out of range integer given to LinkedList");
   }
   int count = -1;
   Node *search = head;
   while (search != nullptr)
   {
      if (count == i)
      {
         return search->tile;
      }
      count++;
      search = search->next;
   }
   throw std::invalid_argument("out of range integer given to LinkedList");
}
void LinkedList::addFront(Tile *tile)
{
   head->next = new Node(tile, head->next);
}
void LinkedList::addBack(Tile *tile)
{
   // if (head->next != nullptr) {
   //    Node* current = head;
   //    while (current->next != nullptr) {
   //       current = current->next;
   //    }
   //    current->next = new Node(tile,current->next);
   // }
   // else {
   //    head->next = new Node(tile, head->next);
   // }
   Node *node = new Node();
   node->tile = new Tile(*tile);
   node->next = nullptr;

   if (this->head == nullptr)
   {
      this->head = node;
   }
   else
   {
      Node *current = this->head;
      while (current->next != nullptr)
      {
         current = current->next;
      }
      current->next = node;
   }
}
void LinkedList::delNode(int i)
{
   if (i < 0)
   {
      throw std::invalid_argument("out of range integer given to LinkedList");
   }
   int count = 0;
   Node *search = head;
   while (search != nullptr)
   {
      if (count == i)
      {
         Node *target = search->next;
         search->next = search->next->next;
         delete target;
      }
      count++;
      search = search->next;
   }
   throw std::invalid_argument("out of range integer given to LinkedList");
}
Tile *LinkedList::popNode()
{
   if (head->next != nullptr)
   {
      Node *current = head;
      while (current->next->next != nullptr)
      {
         current = current->next;
      }
      Tile *temp = new Tile(*(current->next->tile));
      delete current->next;
      current->next = nullptr;
      return temp;
   }
   throw std::invalid_argument("no nodes available to pop");
}