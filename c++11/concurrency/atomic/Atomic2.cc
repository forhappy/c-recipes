#include <iostream>             // std::cout
#include <atomic>               // std::atomic
#include <thread>               // std::thread, std::this_thread::yield

std::atomic <int> foo = 0;

void set_foo(int x)
{
    foo = x; // 调用 std::atomic::operator=().
}

void print_foo()
{
    while (foo == 0) { // wait while foo == 0
        std::this_thread::yield();
    }
    std::cout << "foo: " << foo << '\n';
}

int main()
{
    std::thread first(print_foo);
    std::thread second(set_foo, 10);
    first.join();
    second.join();
    return 0;
}
