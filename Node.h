
#ifndef ASSIGN2_NODE_H
#define ASSIGN2_NODE_H

template <typename T>

class Node {
public:

   Node(T* type, Node* next);
   Node(Node& other);

   T* type;
   Node* next;
};

#endif // ASSIGN2_NODE_H
