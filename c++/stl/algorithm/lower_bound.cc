// lower_bound/upper_bound example
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

template <typename ForwardIterator, class T>
ForwardIterator my_lower_bound(ForwardIterator first,
        ForwardIterator last, const T& value)
{
    ForwardIterator it;
    typename std::iterator_traits<ForwardIterator>::difference_type count, step;
    count = std::distance(first, last);
    while (count > 0) {
        it = first;
        step = count / 2;
        std::advance(it, step);
        if (*it < value) { // or: if (comp(*it,value)), for the comp version
            first = ++it;
            count -= step + 1;
        }
        else count = step;
    }
    return first;
}

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
