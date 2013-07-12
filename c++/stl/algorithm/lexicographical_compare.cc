// lexicographical_compare example
#include <iostream>
#include <algorithm>
#include <cctype>

// a case-insensitive comparison function:
bool mycomp (char c1, char c2)
{ return tolower(c1) < tolower(c2); }

int main () {
  char first[]="Apple";         // 5 letters
  char second[]="apartment";    // 9 letters

  std::cout << "Using default comparison (operator<): ";
  if (std::lexicographical_compare(first,first+5,second,second+9))
    std::cout << first << " is less than " << second << std::endl;
  else if (std::lexicographical_compare(second,second+9,first,first+5))
      std::cout << first << " is greater than " << second << std::endl;
  else
    std::cout << first << " and " << second << " are equivalent\n";


  std::cout << "Using mycomp as comparison object: ";
  if (std::lexicographical_compare(first,first+5,second,second+9,mycomp))
    std::cout << first << " is less than " << second << std::endl;
  else
    if (std::lexicographical_compare(second,second+9,first,first+5,mycomp))
      std::cout << first << " is greater than " << second << std::endl;
  else
    std::cout << first << " and " << second << " are equivalent\n";

  return 0;
}
