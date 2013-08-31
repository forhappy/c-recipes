class Solution {
public:
    std::vector<vector<int> > generateMatrix(int n) {
        std::vector<vector<int> > matrix(n, vector<int>(n));
        if (n == 0) return matrix;
        ssize_t beginX = 0, endX = n - 1;
        ssize_t beginY = 0, endY = n - 1;
        int num = 1;
        while (true) {
            for (ssize_t i = beginX; i <= endX; ++i)
                matrix[beginY][i] = num++;
            if (++beginY > endY) break;
            for (ssize_t i = beginY; i <= endY; ++i)
                matrix[i][endX] = num++;
            if (beginX > --endX) break;
            for (ssize_t i = endX; i >= beginX; --i)
                matrix[endY][i] = num++;
            if (beginY > --endY) break;
            for (ssize_t i = endY; i >= beginY; --i)
                matrix[i][beginX] = num++;
            if (++beginX > endX) break;
        }
        return matrix;
    }
};
