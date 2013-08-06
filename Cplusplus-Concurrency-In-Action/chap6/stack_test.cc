/*
 * ========================================================================
 *
 *       Filename:  stack_test.cc
 *
 *    Description:  Test thread-safe stack.
 *
 *        Created:  08/05/2013 09:57:47 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include <iostream>
#include <memory>
#include <thread>

#include "stack.h"
#include "gtest/gtest.h"

static const int kStackOperations = 100;

static void stack_push_task(ccia::Stack<int>& stack) {
    for (int i = 0; i < kStackOperations; i++) {
        stack.push(i);
    }
}

static void stack_pop_task(ccia::Stack<int>& stack) {
    for (int i = 0; i < kStackOperations; i++) {
        stack.pop();
    }
}


TEST(Stack, SingleThreadNormal) {
    ccia::Stack<int> stack;
    int value;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    stack.pop(value);
    EXPECT_EQ(4, value);
    stack.pop(value);
    EXPECT_EQ(3, value);
    stack.pop(value);
    EXPECT_EQ(2, value);
    stack.pop(value);
    EXPECT_EQ(1, value);
}

TEST(Stack, MultiThreadNormal) {
    ccia::Stack<int> stack;
    std::thread t1(stack_push_task, std::ref(stack));
    std::thread t2(stack_push_task, std::ref(stack));
    t1.join();
    t2.join();
    std::thread t3(stack_pop_task, std::ref(stack));
    std::thread t4(stack_pop_task, std::ref(stack));
    t3.join();
    t4.join();
}
