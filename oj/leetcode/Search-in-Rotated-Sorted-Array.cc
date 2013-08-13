class Solution {
public:
    int search(int A[], int n, int target) {
        if(NULL == A || 0 == n)
            return -1;
        int left = 0, right = n-1, mid = 0;
        while(left <= right)
        {
            mid = left+(right-left)/2;
            if(A[mid] == target)
                return mid;
            else if(A[mid] > A[right])//left
            {
                if(A[left] <= target && target < A[mid])
                    right = mid - 1;
                else
                    left = mid + 1;

            }
            else//right
            {
                if(A[mid] < target && target <= A[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return -1;
    }
};
