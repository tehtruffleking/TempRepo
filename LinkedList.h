#pragma once
#include "Node.h"

template<typename T>
class LinkedList
{
  private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    int numberOfNodes = 0;

  public:
    LinkedList() = default;

    ~LinkedList()
    {
      clear();
    }

    int size() const { return numberOfNodes; }
    bool isEmpty() const { return numberOfNodes == 0; }

    void prepend(const T& content)
    {
      Node<T>* newNode = new Node<T>(nullptr, head, content);

      if (numberOfNodes == 0)
      {
        head = tail = newNode;
      }
      else
      {
        head->setPrev(newNode);
        head = newNode;
      }
      ++numberOfNodes;
    }

    void append(const T& content)
    {
      Node<T>* newNode = new Node<T>(tail, nullptr, content);

      if (numberOfNodes == 0)
      {
        head = tail = newNode;
      }
      else
      {
        tail->setNext(newNode);
        tail = newNode;
      }
      ++numberOfNodes;
    }

    // inserts a node at the given slot, a location between two nodes, by creating a new node and linking it in
    void insert(const T& content, int slot)
    {
      int numberOfSlots = numberOfNodes - 1;

      if (numberOfNodes == 0)
      {
        prepend(content);
      }
      else
      {
        if (slot <= 0)
        {
          prepend(content);
        }
        else if (slot > numberOfSlots)
        {
          append(content);
        }
        else
        {
          Node<T>* current;
          Node<T>* newNode;

          if (slot > numberOfSlots / 2)
          {
            slot = numberOfNodes - slot;
            current = tail;
            while (slot > 0)
            {
              --slot;
              current = current->getPrev();
            }
            newNode = new Node<T>(current, current->getNext(), content);
            current->getNext()->setPrev(newNode);
            current->setNext(newNode);
          }
          else
          {
            current = head;
            while (slot > 0)
            {
              --slot;
              current = current->getNext();
            }
            newNode = new Node<T>(current->getPrev(), current, content);
            current->getPrev()->setNext(newNode);
            current->setPrev(newNode);
          }
          ++numberOfNodes;
        }
      }
    }

    // symmetric dual of prepend: it removes the first node, at the head
    bool top()
    {
      bool success = false;

      if (numberOfNodes == 0)
      {
        // replace this later with a throw error or throw exception for better systems integration
        std::cout << "list is empty\n";
      }
      else
      {
        if (numberOfNodes == 1)
        {
          delete head;
          head = tail = nullptr;
        }
        else
        {
          Node<T>* current = head;
          head = head->getNext();

          delete current;
        }
        --numberOfNodes;
        success = true;
      }

      return success;
    }

    // symmetric dual of append: it removes the last node, at the tail
    bool tail()
    {
      bool success = false;

      if (numberOfNodes == 0)
      {
        // maybe replace this later with a throw error or throw exception for better systems integration
        std::cout << "list is empty\n";
      }
      else
      {
        if (numberOfNodes == 1)
        {
          delete tail;
          tail = head = nullptr;
        }
        else
        {
          Node<T>* current = tail;
          tail = tail->getPrev();

          delete current;
        }
        --numberOfNodes;
        success = true;
      }

      return success;
    }

    // symmetric dual of insert: removes node from given location
    // remark: symmetry is fuzzy as we are removing a specific node, treating location and node as the same, since removing from a slot makes less intuitive sense: would we remove the node to the left or right of the slight?
    bool remove(int location)
    {
      bool success = false;
      int numberOfSlots = numberOfNodes - 1;

      if (numberOfNodes == 0)
      {
        // maybe replace this later with a throw error or throw exception for better systems integration and debugging support
        std::cout << "list is empty\n";
      }
      else
      {
        if (location <= 0)
        {
          success = top();
        }
        else if (location > numberOfSlots)
        {
          success = tail();
        }
        else
        {
          Node<T>* current;

          if (location > numberOfNodes / 2)
          {
            location = numberOfNodes - location;
            current = tail;
            while (location > 0)
            {
              --location;
              current = current->getPrev();
            }
            current->getNext()->setPrev(current->getPrev());
            current->getPrev()->setNext(current->getNext());
          }
          else
          {
            current = head;
            while (location > 1)
            {
              --location;
              current = current->getNext();
            }
            current->getPrev()->setNext(current->getNext());
            current->getNext()->setPrev(current->getPrev());
          }
          --numberOfNodes;
        }
      }

      return success;
    }

    bool clear()
    {
      bool success = false;

      while ((success = top()) != false)
      {

      }

      return !success;
    }
};
