class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0) return 0;
        int ref = 0, fast = 0;
        for (int i = 0; i < n; i++) {
            if (A[fast] == A[ref]) {
                fast++;
            } else {
                A[ref + 1] = A[fast];
                ref++, fast++;
            }
        }
        return ref + 1;
    }
};
