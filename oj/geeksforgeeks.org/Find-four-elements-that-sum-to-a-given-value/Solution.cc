// http://www.geeksforgeeks.org/find-four-numbers-with-sum-equal-to-given-sum/
//
# include <stdio.h>
# include <stdlib.h>

/* A naive solution to print all combination of 4 elements in A[]
  with sum equal to X */
void findFourElements(int A[], int n, int X)
{
  // Fix the first element and find other three
  for (int i = 0; i < n-3; i++)
  {
    // Fix the second element and find other two
    for (int j = i+1; j < n-2; j++)
    {
      // Fix the third element and find the fourth
      for (int k = j+1; k < n-1; k++)
      {
        // find the fourth
        for (int l = k+1; l < n; l++)
           if (A[i] + A[j] + A[k] + A[l] == X)
              printf("%d, %d, %d, %d", A[i], A[j], A[k], A[l]);
      }
    }
  }
}

// 1) Sort the input array.
// 2) Fix the first element as A[i] where i is from 0 to n–3.
//    After fixing the first element of quadruple, fix the second element
//    as A[j] where j varies from i+1 to n-2. Find remaining two elements
//    in O(n) time

/* Following function is needed for library function qsort(). Refer
   http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */
int compare (const void *a, const void * b)
{  return ( *(int *)a - *(int *)b ); }

/* A sorting based solution to print all combination of 4 elements in A[]
   with sum equal to X */
void find4Numbers(int A[], int n, int X)
{
    int l, r;

    // Sort the array in increasing order, using library
    // function for quick sort
    qsort (A, n, sizeof(A[0]), compare);

    /* Now fix the first 2 elements one by one and find
       the other two elements */
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i+1; j < n - 2; j++)
        {
            // Initialize two variables as indexes of the first and last 
            // elements in the remaining elements
            l = j + 1;
            r = n-1;

            // To find the remaining two elements, move the index 
            // variables (l & r) toward each other.
            while (l < r)
            {
                if( A[i] + A[j] + A[l] + A[r] == X)
                {
                   printf("%d, %d, %d, %d", A[i], A[j],
                                           A[l], A[r]);
                   l++; r--;
                }
                else if (A[i] + A[j] + A[l] + A[r] < X)
                    l++;
                else // A[i] + A[j] + A[l] + A[r] > X
                    r--;
            } // end of while
        } // end of inner for loop
    } // end of outer for loop
}

/* Driver program to test above function */
int main()
{
    int A[] = {1, 4, 45, 6, 10, 12};
    int X = 21;
    int n = sizeof(A)/sizeof(A[0]);
    find4Numbers(A, n, X);
    return 0;
}
