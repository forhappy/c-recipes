/*
 * ========================================================================
 *
 *       Filename:  Stack.h
 *
 *    Description:  A thread-safe stack using locks.
 *
 *        Created:  08/05/2013 09:42:49 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */

#ifndef _THREADSAFE_STACK_H_
#define _THREADSAFE_STACK_H_

#include <exception>
#include <mutex>
#include <memory>
#include <stack>

namespace ccia {

struct empty_stack: std::exception {
    const char * what() const throw() {
        return "pop: empty stack.";
    }
};

template<typename T>
class Stack {
private:
    std::stack<T> data;
    mutable std::mutex m;
public:
    Stack() {}

    Stack(const Stack& other) {
        std::lock_guard<std::mutex> lock(other.m);
        data = other.data;
    }

    Stack& operator=(const Stack& other) = delete;

    void push(T new_value) {
        std::lock_guard<std::mutex> lock(m);
        data.push(std::move(new_value));
    }

    std::shared_ptr<T> pop() {
        std::lock_guard<std::mutex> lock(m);
        if (data.empty()) throw empty_stack();
        std::shared_ptr<T> const res(
                std::make_shared<T>(std::move(data.top())));
        data.pop();
        return res;
    }

    void pop(T& value) {
        std::lock_guard<std::mutex> lock(m);
        if (data.empty()) throw empty_stack();
        value = std::move(data.top());
        data.pop();
    }

    bool empty() const {
        std::lock_guard<std::mutex> lock(m);
        return data.empty();
    }
};

}

#endif // _THREADSAFE_STACK_H_
