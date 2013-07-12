// lower_bound/upper_bound example
#include <iostream>
#include <algorithm>
#include <vector>

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints, myints + 8);           // 10 20 30 30 20 10 10 20
  std::vector<int>::iterator low, up;

  sort(v.begin(), v.end());                 // 10 10 10 20 20 20 30 30

  low = lower_bound (v.begin(), v.end(), 20); //         ^
  up  = upper_bound (v.begin(), v.end(), 20); //               ^

  std::cout << "lower_bound at position " << int(low- v.begin()) << std::endl;
  std::cout << "upper_bound at position " << int(up - v.begin()) << std::endl;

  return 0;
}
