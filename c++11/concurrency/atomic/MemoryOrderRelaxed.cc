/*
 * ========================================================================
 *
 *       Filename:  MemoryOrerRelaxed.cc
 *
 *    Description:  std::memory_order_relaxed example.
 *
 *        Created:  08/08/2013 11:37:53 AM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * ========================================================================
 */
#include <vector>
#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> cnt = ATOMIC_VAR_INIT(0);

void f()
{
    for(int n = 0; n < 1000; ++n) {
        cnt.fetch_add(1, std::memory_order_relaxed);
    }
}

int main(int argc, const char* argv[])
{
    std::vector<std::thread> v;
    for(int n = 0; n < 10; ++n) {
        v.emplace_back(f);
    }
    for(auto& t : v) {
        t.join();
    }
    std::cout << "Final counter value is " << cnt << '\n';
}
