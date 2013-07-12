// min_element/max_element
#include <iostream>
#include <algorithm>

bool myfn(int i, int j) { return i < j; }

struct myclass {
  bool operator() (int i,int j) { return i < j; }
} myobj;

int main () {
  int myints[] = {3,7,2,5,6,4,9};

  // using default comparison:
  std::cout << "The smallest element is " << *std::min_element(myints, myints + 7) << std::endl;
  std::cout << "The largest element is " << *std::max_element(myints, myints + 7) << std::endl;

  // using function myfn as comp:
  std::cout << "The smallest element is " << *std::min_element(myints, myints + 7, myfn) << std::endl;
  std::cout << "The largest element is " << *std::max_element(myints, myints + 7, myfn) << std::endl;

  // using object myobj as comp:
  std::cout << "The smallest element is " << *std::min_element(myints, myints + 7, myobj) << std::endl;
  std::cout << "The largest element is " << *std::max_element(myints, myints + 7, myobj) << std::endl;

  return 0;
}
