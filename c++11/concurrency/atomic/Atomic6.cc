#include <iostream>       // std::cout
#include <atomic>         // std::atomic
#include <thread>         // std::thread
#include <vector>         // std::vector

// a simple global linked list:
struct Node { int value; Node* next; };
std::atomic<Node*> list_head(nullptr);

void append(int val)
{
    // append an element to the list
    Node* newNode = new Node{val, list_head};

    // next is the same as: list_head = newNode, but in a thread-safe way:
    while (!list_head.compare_exchange_weak(newNode->next,newNode)) {}
    // (with newNode->next updated accordingly if some other thread just appended another node)
}

int main ()
{
    // spawn 10 threads to fill the linked list:
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) threads.push_back(std::thread(append,i));
    for (auto& th : threads) th.join();

    // print contents:
    for (Node* it = list_head; it!=nullptr; it=it->next)
        std::cout << ' ' << it->value;

    std::cout << '\n';

    // cleanup:
    Node* it; while (it=list_head) {list_head=it->next; delete it;}

    return 0;
}
