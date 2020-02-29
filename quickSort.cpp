#include <iostream>
#include "quickSort.hpp"
using namespace std;

// A utility function to swap two elementus
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


void swift0(int *arr,int *scoreSum, int n) {
    int count = n-1;  // Count of non-zero elements

    // Traverse the array. If element encountered is non-
    // zero, then replace the element at index 'count'
    // with this element
    for (int i = n-1; i >= 0; i--) {
        if (scoreSum[i] != 0) {
            scoreSum[count] = scoreSum[i]; // here count is
            swap(arr[count],arr[i]);
            count--;
        }
    }
    // Now all non-zero elements have been shifted to
    // front and  'count' is set as index of first 0.
    // Make all elements 0 from count to end.
    while (count >= 0)
        scoreSum[count--] = 0;
}


void pushZerosToEnd(int *arr,int *scoresCopy,int N) {
    int mv = 0;
    int i;
    for(i=1;i<=N;i++) {
        if(scoresCopy[N-i] == 0) {
            mv++;
        }
        if(N-i-mv >= 0) {
            // int tmp = arr[N-i];
            // arr[N-i] = arr[N-i-mv];
            swap(arr[N-i],arr[N-i-mv]);
            scoresCopy[N-i] = scoresCopy[N-i-mv];

            // arr[N-i-mv] = tmp;
            // swap(scoresCopy[N-i],scoresCopy[N-i-mv]);

        }
        else {
            // arr[N-i] = -10;
            scoresCopy[N-i] = 0;

        }
        printArray(arr,N);
        printArray(scoresCopy,N);
        cout <<endl;
    }
}
/* This function takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller (smaller than pivot)
to left of pivot and all greater elements to right
of pivot */
int partition (int arr[], int low, int high, int arr2[])
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
            swap(&arr2[i], &arr2[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    swap(&arr2[i + 1], &arr2[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
arr[] --> Array to be sorted,
low --> Starting index,
high --> Ending index */
void quickSort(int arr[], int low, int high, int arr2[])
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = partition(arr, low, high, arr2);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1, arr2);
        quickSort(arr, pi + 1, high, arr2);
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

//
// int main(void) {
//     int arr[6] = {1,2,3,4,5,6};
//     int scores[6] = {0,1,0,3,0,0};
//
//     printArray(arr,6);
//     printArray(scores,6);
//     cout <<endl;
//     pushZerosToEnd(arr,scores,6);
//     printArray(arr,6);
//     printArray(scores,6);
// }
