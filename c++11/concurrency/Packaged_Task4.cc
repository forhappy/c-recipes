#include <iostream>     // std::cout
#include <utility>      // std::move
#include <future>       // std::packaged_task, std::future
#include <thread>       // std::thread

int main ()
{
    std::packaged_task<int(int)> tsk([](int x) { return x * 3; })); // package task

    std::future<int> fut = tsk.get_future();   // 获取 future 对象.

    std::thread(std::move(tsk), 100).detach();   // 生成新线程并调用packaged_task.

    int value = fut.get();                     // 等待任务完成, 并获取结果.

    std::cout << "The triple of 100 is " << value << ".\n";

    return 0;
}
