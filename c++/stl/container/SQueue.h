/*
 * ========================================================================
 *
 *       Filename:  SQueue.h
 *
 *    Description:  Simple Queue.
 *
 *        Created:  10/12/2013 02:52:47 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */
#ifndef SQUEUE_H__
#define SQUEUE_H__

#include <stdexcept>
#include <iterator>

// A simple queue as a singly-linked list
template<typename T>
class SQueue {

private:
   // The Node class holds the value
   class Node {
   public:
      Node(const T& val) : next_(NULL), val_(val) {}
      T& getVal() {return(val_);}
      Node* next_;
   private:
      T val_;
   };

   Node* root_;
   Node* last_;

public:
   SQueue() : root_(NULL), last_(NULL) {}
  ~SQueue()
   {
      delete root_;
   }

   void pushBack(const T& val)
   {
      if (root_ == NULL)
      {
         root_ = new Node(val);
         last_ = root_;
      }
      else
      {
         Node* p = new Node(val);
         last_->next_ = p;
         last_ = p;
      }
   }

   T popFront()
   {
      if (root_ == NULL)
      {
         throw std::out_of_range("Queue is empty");
      }
      else
      {
         Node* p = root_;
         root_ = root_->next_;
         return(root_->getVal());
      }
   }

   // Here is my custom iterator.  The only kind of iterator this data
   // structure can reasonably support is a forward iterator, so that's
   // what I provide.  I embedded the definition of the iterator within
   // the class it will iterate through for convenience.
   class Iterator :
      public std::iterator<std::forward_iterator_tag, T> {
   public:
      Iterator(Node* p) : node_(p) {}
     ~Iterator() {}

      // The assignment and relational operators are straightforward
      Iterator& operator=(const Iterator& other)
      {
         node_ = other.node_;
         return(*this);
      }

      bool operator==(const Iterator& other)
      {
         return(node_ == other.node_);
      }

      bool operator!=(const Iterator& other)
      {
         return(node_ != other.node_);
      }

      // Update my state such that I refer to the next element in the
      // SQueue.
      Iterator& operator++()
      {
         if (node_ != NULL)
         {
            node_ = node_->next_;
         }
         return(*this);
      }

      Iterator& operator++(int)
      {
         Iterator tmp(*this);
         ++(*this);
         return(tmp);
      }

      // Return a reference to the value in the node.  I do this instead
      // of returning by value so a caller can update the value in the
      // node directly.
      T& operator*()
      {
         return(node_->getVal());
      }

      T* operator->()
      {
         return(&*(SQueue<T>::Iterator)*this);
      }

   private:
      Node* node_;
   };

   Iterator begin()
   {
      return(Iterator(root_));
   }

   Iterator end()
   {
      return(Iterator(NULL));
   }
};

#endif // SQUEUE_H__
