// inplace_merge example
#include <iostream>
#include <algorithm>
#include <vector>

int main () {
  int first[] = {5, 10, 15, 20, 25};
  int second[] = {50, 40, 30, 20, 10};
  std::vector<int> v(10);
  std::vector<int>::iterator it;

  std::sort(first, first + 5);
  std::sort(second, second + 5);

  std::copy(first, first + 5, v.begin());
  std::copy(second, second + 5, v.begin() + 5);

  inplace_merge(v.begin(), v.begin() + 5, v.end());

  std::cout << "The resulting vector contains:";
  for (it = v.begin(); it != v.end(); ++it)
    std::cout << " " << *it;

  std::cout << std::endl;

  return 0;
}
