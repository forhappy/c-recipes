/*
 * ========================================================================
 *
 *       Filename:  queue.h
 *
 *    Description:  a lock-free queue with a single producer
 *    and single-consumer.
 *
 *        Created:  08/06/2013 09:44:12 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */

#include <atomic>
#include <memory>

namespace ccia {

template <typename T>
class Queue {
private:
    struct Node {
        std::shared_ptr<T> data;
        Node* next;

        Node(): next(nullptr) {}
    };

    std::atomic<Node*> head;
    std::atomic<Node*> tail;

    Node* PopHead() {
        Node* const old_head = head.load();
        if (old_head == tail.load()) return nullptr;
        head.store(old_head->next);
        return old_head;
    }

public:
    Queue(): head(new Node), tail(head.load()) {}
    Queue(const Queue& other) = delete;
    Queue& operator=(const Queue& other) = delete;
    ~Queue() {
        while(Node* const old_head = head.load()) {
        head.store(old_head->next)};
        delete old_head;
    }

    std::shared_ptr<T> pop() {
        Node* old_head = PopHead();
        if (!old_head) return std::shared_ptr<T>();
        std::shared_ptr<T> const res(old_head->data);
        delete old_head;
        return res;
    }

    void push(T value) {
        std::shared_ptr<T> new_data(std::make_shared<T>(value));
        Node* p = new Node;
        Node* const old_tail = tail.load();
        old_tail->data.swap(new_data);
        old_tail->next = p;
        tail.store(p);
    }
};

}
