// set_union example
#include <iostream>
#include <algorithm>
#include <vector>

int main () {
  int first[] = {5, 10, 15, 20, 25};
  int second[] = {50, 40, 30, 20, 10};
  std::vector<int> v(10); // 0  0  0  0  0  0  0  0  0  0
  std::vector<int>::iterator it;

  std::sort(first, first + 5);     //  5 10 15 20 25
  std::sort(second, second + 5);   // 10 20 30 40 50

  it = set_union(first, first + 5, second, second + 5, v.begin());
  // 5 10 15 20 25 30 40 50  0  0

  std::cout << "union has " << int(it - v.begin()) << " elements.\n";

  return 0;
}
