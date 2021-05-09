
#include "LinkedList.h"
#include <stdexcept>

LinkedList::LinkedList()
{
   head = nullptr;
}

LinkedList::LinkedList(LinkedList &other)
{
   head = nullptr;
   for (int i = 0; i < other.size(); ++i)
   {
      Tile *tile = new Tile(*other.get(i));
      add_back(tile);
   }
}
LinkedList::~LinkedList()
{
   clear();
}

int LinkedList::size()
{

   int length = 0;

   Node *current = head;
   while (current != nullptr)
   {
      ++length;
      current = current->next;
   }
   return length;
}

Tile *LinkedList::get(int index)
{
   Tile *retTile = nullptr;

   if (index >= 0 && index < size())
   {

      int counter = 0;
      Node *current = head;

      while (counter < index)
      {
         ++counter;
         current = current->next;
      }

      retTile = current->tile;
   }
   return retTile;
}
std::string LinkedList::getContentAsString()
{
   std::string retValue = "";
   for (int i = 0; i < this->size(); i++)
   {
      retValue += this->get(i)->fullName;
      if (i < this->size() - 1)
      {
         retValue += ",";
      }
   }

   return retValue;
}
void LinkedList::add_front(Tile *data)
{
   Node *node = new Node();
   node->tile = data;
   node->next = head;
   head = node;
}
void LinkedList::add_back(Tile *data)
{
   Node *node = new Node();
   node->tile = new Tile(*data);
   node->next = nullptr;

   if (head == nullptr)
   {
      head = node;
   }
   else
   {
      Node *current = head;
      while (current->next != nullptr)
      {
         current = current->next;
      }
      current->next = node;
   }
}

void LinkedList::remove_front()
{
   if (head != nullptr)
   {
      Node *toDelete = head;
      head = head->next;

      // delete toDelete->tile;
      delete toDelete;
   }
   else
   {
      throw std::runtime_error("Nothing to remove");
   }
}
void LinkedList::remove_back()
{

   if (head != nullptr)
   {
      Node *current = head;
      //pre should point to node before current;
      Node *prev = nullptr;

      while (current->next != nullptr)
      {
         prev = current;
         current = current->next;
      }

      if (prev == nullptr)
      {
         head = nullptr;
      }
      else
      {
         prev->next = nullptr;
      }

      delete current->tile;
      delete current;
   }
}

void LinkedList::remove(int index)
{
   if (index >= 0 && index < size())
   {
      if (head != nullptr)
      {
         int counter = 0;
         Node *current = head;
         //pre should point to node before current;
         Node *prev = nullptr;

         while (counter != index)
         {
            ++counter;
            prev = current;
            current = current->next;
         }

         if (prev == nullptr)
         {
            head = current->next;
         }
         else
         {
            prev->next = current->next;
         }

         // delete current->tile;
         delete current;
      }
   }
}

void LinkedList::clear()
{
   while (head != nullptr)
   {
      remove_front();
   }
}

int LinkedList::getIndex(std::string tileString) {
   int index = -1;
   
   for (int i = 0; i < this->size(); i++) {
      if (this->get(i)->fullName.compare(tileString) == 0) {
         index = i;
      }
   }

   return index;
}

// Tile *LinkedList::popNode()
// {
//    if (head->next != nullptr)
//    {
//       Node *current = head;
//       while (current->next->next != nullptr)
//       {
//          current = current->next;
//       }
//       Tile *temp = new Tile(*(current->next->tile));
//       delete current->next;
//       current->next = nullptr;
//       return temp;
//    }
//    throw std::invalid_argument("no nodes available to pop");
// }