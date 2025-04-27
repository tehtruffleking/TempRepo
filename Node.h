#pragma once

template<typename T>
class Node
{
  private:
    Node<T>* prevNode = nullptr;
    Node<T>* nextNode = nullptr;
    T contents = T();

  public:
    Node() = default;

    // consider explicit as well as enchanced constructors as future projects make use of the Node template class
    Node(Node<T>* prev, Node<T>* next, const T& content = T())
      : prevNode(prev), nextNode(next), contents(content)
    {}

    // consider noexcept as well as enchanced destructors as future projects make use of the Node template class
    ~Node() = default;

    Node<T>* getPrev() const { return prevNode; }
    Node<T>* getNext() const { return nextNode; }
    const T& getContents() const { return contents; }

    void setPrev(Node<T>* prev) { prevNode = prev; }
    void setNext(Node<T>* next) { nextNode = next; }
    void setContents(const T& content) { contents = content; }
    void clearNode() { prevNode = nextNode = nullptr; contents = T(); }
};
