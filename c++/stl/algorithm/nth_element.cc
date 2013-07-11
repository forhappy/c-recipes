// nth_element example
#include <iostream>
#include <algorithm>
#include <vector>

bool myfunction (int i,int j) { return (i < j); }

int main () {
  std::vector<int> myvector;
  std::vector<int>::iterator it;

  // set some values:
  for (int i=1; i<10; i++) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9

  random_shuffle(myvector.begin(), myvector.end());

  // using default comparison (operator <):
  nth_element(myvector.begin(), myvector.begin() + 5, myvector.end());

  // using function as comp
  nth_element(myvector.begin(), myvector.begin() + 5, myvector.end(), myfunction);

  // print out content:
  std::cout << "myvector contains:";
  for (it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << " " << *it;

  std::cout << std::endl;

  return 0;
}
