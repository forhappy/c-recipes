#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

#include <boost/scoped_array.hpp>

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

int EditDistance(const std::string& source, const std::string& target) {
    if (source == target) return 0;
    if (source.length() == 0) return target.length();
    if (target.length() == 0) return source.length();

    std::vector<std::vector<int> > aux_table(source.length() + 1,
            std::vector<int>(target.length() + 1, 0));

    for (size_t i = 0; i < source.length(); i++) aux_table[i][0] = i;
    for (size_t i = 0; i < target.length(); i++) aux_table[0][i] = i;

    for (size_t i = 1; i <= source.length(); i++) {
        for (size_t j = 1; j <= target.length(); j++) {
            if (source[i] == target[j]) aux_table[i][j] = aux_table[i - 1][j - 1];
            else {
                aux_table[i][j] = min3(aux_table[i - 1][j] + kDeletionCost,
                        aux_table[i][j - 1] + kInsertionCost,
                        aux_table[i - 1][j - 1] + kReplacementCost);
            }
        }
    }

    return aux_table[source.length() - 1][target.length() - 1];

}



/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{

    std::string source = "xxxhello";
    std::string target = "hellox";
    std::cout << EditDistance(source, target) << std::endl;
    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
