// equal_range example
#include <iostream>
#include <algorithm>
#include <vector>

bool mygreater (int i,int j) { return (i>j); }

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);                         // 10 20 30 30 20 10 10 20
  std::pair<std::vector<int>::iterator,std::vector<int>::iterator> bounds;

  // using default comparison:
  sort(v.begin(), v.end());                              // 10 10 10 20 20 20 30 30
  bounds = equal_range(v.begin(), v.end(), 20);            //          ^        ^

  // using "mygreater" as comp:
  sort (v.begin(), v.end(), mygreater);                   // 30 30 20 20 20 10 10 10
  bounds=equal_range(v.begin(), v.end(), 20, mygreater); //       ^        ^

  std::cout << "bounds at positions " << int(bounds.first - v.begin());
  std::cout << " and " << int(bounds.second - v.begin()) << std::endl;

  return 0;
}
