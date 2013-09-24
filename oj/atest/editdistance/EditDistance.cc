#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <climits>
#include <iostream>
#include <sstream>
#include <vector>
#include <iterator>

#define min3(x, y, z) ({			\
	typeof(x) _min1 = (x);			\
	typeof(y) _min2 = (y);			\
	typeof(z) _min3 = (z);			\
	(void) (&_min1 == &_min2);		\
	(void) (&_min1 == &_min3);		\
	_min1 < _min2 ? (_min1 < _min3 ? _min1 : _min3) : \
		(_min2 < _min3 ? _min2 : _min3); })

const int kInsertionCost   = 1;
const int kDeletionCost    = 1;
const int kReplacementCost = 1;

int EditDistance(const std::vector<int>& source,
                 const std::vector<int>& target) {
    if (source == target) return 0;
    if (source.size() == 0) return target.size();
    if (target.size() == 0) return source.size();

    std::vector<std::vector<int> > aux_table(source.size() + 1,
            std::vector<int>(target.size() + 1, -1));

    for (size_t i = 0; i <= source.size(); i++) aux_table[i][0] = i;
    for (size_t i = 0; i <= target.size(); i++) aux_table[0][i] = i;

    for (size_t i = 1; i <= source.size(); i++) {
        for (size_t j = 1; j <= target.size(); j++) {
            if (source[i - 1] == target[j - 1]) {
                aux_table[i][j] = aux_table[i - 1][j - 1];
            }
            else {
                aux_table[i][j] = min3(aux_table[i - 1][j] + kDeletionCost,
                        aux_table[i][j - 1] + kInsertionCost,
                        aux_table[i - 1][j - 1] + kReplacementCost);
            }
        }
    }

    return aux_table[source.size()][target.size()];
}

int EditDistance2(const std::vector<std::string>& source,
                 const std::vector<std::string>& target) {
    if (source == target) return 0;
    if (source.size() == 0) return target.size();
    if (target.size() == 0) return source.size();

    std::vector<std::vector<int> > aux_table(source.size() + 1,
            std::vector<int>(target.size() + 1, -1));

    for (size_t i = 0; i <= source.size(); i++) aux_table[i][0] = i;
    for (size_t i = 0; i <= target.size(); i++) aux_table[0][i] = i;

    for (size_t i = 1; i <= source.size(); i++) {
        for (size_t j = 1; j <= target.size(); j++) {
            if (!source[i - 1].compare(target[j - 1])) {
                aux_table[i][j] = aux_table[i - 1][j - 1];
            }
            else {
                aux_table[i][j] = min3(aux_table[i - 1][j] + kDeletionCost,
                        aux_table[i][j - 1] + kInsertionCost,
                        aux_table[i - 1][j - 1] + kReplacementCost);
            }
        }
    }

    return aux_table[source.size()][target.size()];
}

void Tokenize(const std::string& str, std::vector<std::string>& tokens,
              const std::string& delimiters = " ", bool trim_space = true)
{
   std::string::size_type pos, lastPos = 0;
   while(true) {
      pos = str.find_first_of(delimiters, lastPos);
      if(pos == std::string::npos) {
         pos = str.length();
         if(pos != lastPos || !trim_space)
            tokens.push_back(
                    std::vector<std::string>::value_type(str.data() + lastPos,
                        pos - lastPos));
         break;
      } else {
         if(pos != lastPos || !trim_space)
            tokens.push_back(
                    std::vector<std::string>::value_type(str.data() + lastPos,
                        pos - lastPos));
      }

      lastPos = pos + 1;
   }
}

int differ(std::string string1, std::string string2)
{
    std::vector<std::string> vecstr1;
    std::vector<std::string> vecstr2;

    Tokenize(string1, vecstr1);
    Tokenize(string2, vecstr2);

    return EditDistance2(vecstr1, vecstr2);
}


/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{

    // int a[] = {1, 2, 3, 4, 5, 5, 6};
    // int b[] = {1, 2, 4, 4, 5, 4, 7};

    // int a[] = {1, 2, 4};
    // int b[] = {1, 2, 3};

    // std::vector<int> source(a, a + sizeof(a) / sizeof(a[0]));
    // std::vector<int> target(b, b + sizeof(b) / sizeof(b[0]));

    // std::cout << EditDistance(source, target) << std::endl;

    // std::vector<std::string> string1;
    // string1.push_back("Hadoop");
    // string1.push_back("in");
    // string1.push_back("action");

    // std::vector<std::string> string2;
    // string2.push_back("Hadoop");
    // string2.push_back("in");
    // string2.push_back("practice");


    // std::cout << EditDistance2(string1, string2) << std::endl;

    // std::vector<std::string> vecstr = Split("hello world   hi", std::string(" "));
    std::string string1 = "hello world    hi in actioxn";
    std::string string2 = "hello world    hihlo ixn action";

    std::cout << differ(string1, string2) << std::endl;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
