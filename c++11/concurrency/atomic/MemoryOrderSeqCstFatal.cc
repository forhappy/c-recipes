/*
 * ========================================================================
 *
 *       Filename:  MemoryOrderSeqCst.cc
 *
 *    Description:  std::memory_order_seq_cst example.
 *
 *        Created:  08/08/2013 11:54:04 AM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */
#include <thread>
#include <atomic>
#include <cassert>
#include <iostream>

std::atomic<bool> x = ATOMIC_VAR_INIT(false);
std::atomic<bool> y = ATOMIC_VAR_INIT(false);
std::atomic<int> z = ATOMIC_VAR_INIT(0);

void write_x()
{
    // x.store(true, std::memory_order_seq_cst);
    // x.store(true, std::memory_order_release);
    x.store(true, std::memory_order_relaxed);
}

void write_y()
{
    // y.store(true, std::memory_order_seq_cst);
    // y.store(true, std::memory_order_release);
    y.store(true, std::memory_order_relaxed);
}

void read_x_then_y()
{
    // while (!x.load(std::memory_order_seq_cst));
    // while (!x.load(std::memory_order_acquire));
    while (!x.load(std::memory_order_relaxed));

    // if (y.load(std::memory_order_seq_cst)) ++z;
    // if (y.load(std::memory_order_acquire)) ++z;
    if (y.load(std::memory_order_relaxed)) ++z;
}

void read_y_then_x()
{
    // while (!y.load(std::memory_order_seq_cst));
    // while (!y.load(std::memory_order_acquire));
    while (!y.load(std::memory_order_relaxed));

    // if (x.load(std::memory_order_seq_cst)) ++z;
    // if (x.load(std::memory_order_acquire)) ++z;
    if (x.load(std::memory_order_relaxed)) ++z;
}

int main()
{
    std::thread a(write_x);
    std::thread b(write_y);
    std::thread c(read_x_then_y);
    std::thread d(read_y_then_x);
    a.join(); b.join(); c.join(); d.join();
    assert(z.load() != 0);  // will never happen
    std::cout << "MemoryOrderSeqCstFatal executed!\n";
}
