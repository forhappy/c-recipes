// http://www.geeksforgeeks.org/print-all-interleavings-of-given-two-strings/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The main function that recursively prints all interleavings.  The variable
// iStr is used to store all interleavings (or output strings) one by one.  
// i is used to pass next available place in iStr
void printIlsRecur (char *str1, char *str2, char *iStr, int m, int n, int i)
{
    // Base case: If all characters of str1 and str2 have been included in
    // output string, then print the output string
    if ( m==0 && n ==0 )
    {
        printf("%s\n", iStr) ;
    }

    // If some characters of str1 are left to be included, then include the 
    // first character from the remaining characters and recur for rest
    if ( m != 0 )
    {
        iStr[i] = str1[0];
        printIlsRecur (str1 + 1, str2, iStr, m-1, n, i+1);
    }

    // If some characters of str2 are left to be included, then include the 
    // first character from the remaining characters and recur for rest
    if ( n != 0 )
    {
        iStr[i] = str2[0];
        printIlsRecur (str1, str2+1, iStr, m, n-1, i+1);
    }
}

// Allocates memory for output string and uses printIlsRecur()
// for printing all interleavings
void printIls (char *str1, char *str2, int m, int n)
{
   // allocate memory for the output string
   char *iStr= (char*)malloc((m+n+1)*sizeof(char));

   // Set the terminator for the output string
   iStr[m+n] = '\0';

   // print all interleavings using printIlsRecur()
   printIlsRecur (str1, str2, iStr, m, n, 0);

   // free memory to avoid memory leak
   free(iStr); 
}

// Driver program to test above functions
int main()
{
    char *str1 = "AB";
    char *str2 = "CD";
    printIls (str1, str2, strlen(str1), strlen(str2));
    return 0;
}
