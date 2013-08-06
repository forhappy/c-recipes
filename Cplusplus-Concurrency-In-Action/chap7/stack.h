/*
 * ========================================================================
 *
 *       Filename:  Stack.h
 *
 *    Description:  A lock-free stack implementation.
 *
 *        Created:  08/05/2013 09:42:49 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */

#ifndef _LOCKFREE_STACK_H_
#define _LOCKFREE_STACK_H_

#include <atomic>
#include <exception>
#include <mutex>
#include <memory>

namespace ccia {

struct empty_stack: std::exception {
    const char * what() const throw() {
        return "pop: empty stack.";
    }
};

template<typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T const& data): data(data) {}
    };

    std::atomic<Node*> head;
public:
    void push(T const& data) {
        Node* const new_node = new Node(data);
        new_node->next = head.load();
        while(!head.compare_exchange_weak(new_node->next, new_node));
    }

    void pop(T& value) {
        Node* old_head = head.load();
        while(!head.compare_exchange_weak(old_head, old_head->next));
        value = old_head->data;
    }
};

}

#endif // _LOCKFREE_STACK_H_
