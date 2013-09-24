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

const int Right = 0, Down = 1, Left = 2, Up = 3;

std::vector<std::vector<int> >GenerateMatrix(int size)
{
    std::vector<std::vector<int> > matrix(size, std::vector<int>(size));
    int count = size / 2;
    int loopcounts = (size + 1)/2;
    int i = count;
    int j = count;
    int current = 1;

    for (int index = 1; index <= loopcounts; index ++) {
        matrix[i][j] = current++;
        while (i < count + index - 1) {
            ++i;
            matrix[i][j] = current++;
        }

        while (j > count - index + 1) {
            --j;
            matrix[i][j] = current++;
        }

        while (i > count - index + 1) {
            --i;
            matrix[i][j] = current++;
        }

        while (j < count + index - 1) {
            ++j;
            matrix[i][j] = current++;
        }
        ++j;
    }
    return matrix;
}

std::string GenerateOutput(std::vector<std::vector<int> > m)
{
    if (m.empty()) return std::string("");

    std::vector<int>::size_type msize = m.size();

    std::string result;

    for (int i = 0; i < msize; i++) {
        for (int j = 0; j < msize; j++) {
            std::stringstream ss;
            ss << m[i][j];
            if (j != msize - 1) ss << "*";
            if (j == msize - 1) ss << "\n";
            result.append(ss.str());
        }
    }

    return result;
}

std::string clockwise(int size)
{
    if (size <= 0) return std::string("");

    std::vector<std::vector<int> > m = GenerateMatrix(size);
    std::string output = GenerateOutput(m);

    return output;
}

/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::string s = clockwise(7);
    std::cout << s;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
