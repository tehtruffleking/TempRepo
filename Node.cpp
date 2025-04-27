#include "Node.h"

template<typename>
Node<T>::Node(Node* prevNode, Node* nextNode, T contents)
  : prevNode(prevNode), nextNode(nextNode), contents(contents)
  {}
