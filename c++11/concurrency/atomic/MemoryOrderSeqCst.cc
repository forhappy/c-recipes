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

std::atomic<bool> x = ATOMIC_VAR_INIT(false);
std::atomic<bool> y = ATOMIC_VAR_INIT(false);
std::atomic<int> z = ATOMIC_VAR_INIT(0);

void write_x()
{
    x.store(true, std::memory_order_seq_cst);
}

void write_y()
{
    y.store(true, std::memory_order_seq_cst);
}

void read_x_then_y()
{
    while (!x.load(std::memory_order_seq_cst))
        ;
    if (y.load(std::memory_order_seq_cst)) {
        ++z;
    }
}

void read_y_then_x()
{
    while (!y.load(std::memory_order_seq_cst))
        ;
    if (x.load(std::memory_order_seq_cst)) {
        ++z;
    }
}

int main()
{
    std::thread a(write_x);
    std::thread b(write_y);
    std::thread c(read_x_then_y);
    std::thread d(read_y_then_x);
    a.join(); b.join(); c.join(); d.join();
    assert(z.load() != 0);  // will never happen
}
