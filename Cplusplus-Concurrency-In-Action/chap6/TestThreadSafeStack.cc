/*
 * ========================================================================
 *
 *       Filename:  TestThreadSafeStack.cc
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

#include "ThreadSafeStack.h"
#include "gtest/gtest.h"

TEST(ThreadSafeStack, SingleThreadNormal) {
    ccia::ThreadSafeStack<int> stack;
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
