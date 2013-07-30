// You are given a set of n types of rectangular 3-D boxes,
// where the i^th box has height h(i), width w(i) and depth d(i)
// (all real numbers). You want to create a stack of boxes which is
// as tall as possible, but you can only stack a box on top of another
// box if the dimensions of the 2-D base of the lower box are each
// strictly larger than those of the 2-D base of the higher box.
// Of course, you can rotate a box so that any side functions as its base.
// It is also allowable to use multiple instances of the same type of box.
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <iostream>
#include <algorithm>
#include <vector>

struct Box {
    int d, w, h;
};

int MaxBoxStackHeight(const std::vector<Box> boxes) {
    assert(boxes.size() > 0);

    std::vector<Box> aux;
    for (int i = 0; i < boxes.size(); i++) {
        aux.push_back(boxes[i]);
        int d = boxes[i].d;
        int w = boxes[i].w;
        int h = boxes[i].h;

        if (d < h) {
            aux.push_back(Box({d, h, w}));
        } else aux.push_back(Box({h, d, w}));

        if (w < h) {
            aux.push_back(Box({w, h, d}));
        } else aux.push_back(Box({h, w, d}));
    }
    std::sort(aux.begin(), aux.end(), [](Box a, Box b) -> bool {
            if (a.d * a.w < b.d * b.w) return false;
            else return true;
            });

    std::vector<Box>::size_type aux_table_size = aux.size();

    std::vector<int> max_table(aux_table_size);
    for (int i = 0; i < aux_table_size; i++) max_table[i] = aux[i].h;
    for (int i = 0; i < aux_table_size; i++) {
        for (int j = 0; j < i; j++) {
            if (aux[j].d > aux[i].d
                    && aux[j].w > aux[i].w) {
                max_table[i] = max_table[j] + aux[i].h;
            }
        }
    }

    return *std::max_element(max_table.begin(), max_table.end());

}


/*
 * ===  FUNCTION  =========================================================
 *         Name:  main
 *  Description:  program entry routine.
 * ========================================================================
 */
int main(int argc, const char *argv[])
{
    std::vector<Box> boxes = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };

    std::cout << MaxBoxStackHeight(boxes) << std::endl;

    return EXIT_SUCCESS;
}  /* ----------  end of function main  ---------- */
