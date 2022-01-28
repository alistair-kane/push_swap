#include <stdio.h>
int	min(int x, int y)
{
	if (x > y)
		return (y);
	else
		return (x);
}

void CopyArray(int B[],int A[],int n)
{
    int i;

    for (i = 0; i < n; i++)
        A[i] = B[i];
}
//  Left run is A[iLeft :iRight-1].
// Right run is A[iRight:iEnd-1  ].
void BottomUpMerge(int A[], int iLeft, int iRight, int iEnd,int B[])
{
    int i,j,k;

    i = iLeft, j = iRight;
    // While there are elements in the left or right runs...
    for (k = iLeft; k < iEnd; k++) {
        printf("Comparison between i: %i and j: %i\n", A[i], A[j]);
        // If left run head exists and is <= existing right run head.
        if (i < iRight && (j >= iEnd || A[i] <= A[j])) {
            B[k] = A[i];
            i = i + 1;
        } else {
            B[k] = A[j];
            j = j + 1;    
        }
    } 
}

// array A[] has the items to sort; array B[] is a work array
void BottomUpMergeSort(int A[],int B[],int n)
{
    int width;
    int i;
    // Each 1-element run in A is already "sorted".
    // Make successively longer sorted runs of length 2, 4, 8, 16... until the whole array is sorted.
    for (width = 1; width < n; width = 2 * width)
    {
        // Array A is full of runs of length width.
        for (i = 0; i < n; i = i + 2 * width)
        {
            printf("Width: %i\n", width);
            // Merge two runs: A[i:i+width-1] and A[i+width:i+2*width-1] to B[]
            // or copy A[i:n-1] to B[] ( if (i+width >= n) )
            BottomUpMerge(A, i, min(i+width, n), min(i+2*width, n), B);
        }
        // Now work array B is full of runs of length 2*width.
        // Copy array B to array A for the next iteration.
        // A more efficient implementation would swap the roles of A and B.
        CopyArray(B, A, n);
        // Now array A is full of runs of length 2*width.
    }
}

int main(void)
{
    int input[] = {6, 3, 7, 2, 8, 4, 9, 1};
    int output[8];
    int size = 8;
    int i;

    BottomUpMergeSort(input, output, size);

    printf("The array is:");
    for (i = 0; i < size ; i++){
         printf("%d ", input[i]);
    }
}