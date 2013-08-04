#include <iostream>       // std::cout
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds

void PauseThread(int n)
{
  std::this_thread::sleep_for(std::chrono::seconds(n));
  std::cout << "pause of " << n << " seconds ended\n";
}

int main()
{
  std::cout << "Spawning and detaching 3 threads...\n";
  std::thread(pause_thread, 1).detach();
  std::thread(pause_thread, 2).detach();
  std::thread(pause_thread, 3).detach();
  std::cout << "Done spawning threads.\n";

  std::cout << "(The main thread will now pause for 5 seconds)\n";
  // give the detached threads time to finish (but not guaranteed!):
  PauseThread(5);
  return 0;
}
