class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        std::vector<int> range(2);
        if (A[std::lower_bound(A, A + n, target) - A] == target) {
            range[0] = std::lower_bound(A, A + n, target) - A;
        } else range[0] = -1;

        if (A[std::upper_bound(A, A + n, target) - A - 1] == target) {
            range[1] = std::upper_bound(A, A + n, target) - A - 1;
        } else range[1] = -1;

        return range;
    }
};
