#include <iostream>       // std::cout
#include <atomic>         // std::atomic
#include <thread>         // std::thread, std::this_thread::yield

std::atomic<int> foo = 0;
std::atomic<int> bar = 0;

void set_foo(int x)
{
    foo = x;
}

void copy_foo_to_bar()
{

    // 如果 foo == 0，则该线程 yield,
    // 在 foo == 0 时, 实际也是隐含了类型转换操作,
    // 因此也包含了 operator T() const 的调用.
    while (foo == 0) std::this_thread::yield();

    // 实际调用了 operator T() const, 将foo 强制转换成 int 类型,
    // 然后调用 operator=().
    bar = static_cast<int>(foo);
}

void print_bar()
{
    // 如果 bar == 0，则该线程 yield,
    // 在 bar == 0 时, 实际也是隐含了类型转换操作,
    // 因此也包含了 operator T() const 的调用.
    while (bar == 0) std::this_thread::yield();
    std::cout << "bar: " << bar << '\n';
}

int main ()
{
    std::thread first(print_bar);
    std::thread second(set_foo, 10);
    std::thread third(copy_foo_to_bar);

    first.join();
    second.join();
    third.join();
    return 0;
}
