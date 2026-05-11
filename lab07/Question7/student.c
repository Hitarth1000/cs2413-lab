#include <stdio.h>
#include <stdlib.h>

/*
Hybrid Merge Sort Lab

Objective:
Implement a hybrid sorting algorithm that combines merge sort and insertion sort.

Idea:
- Merge sort has worst-case time complexity O(n log n).
- Insertion sort has worst-case time complexity O(n^2), but it is fast for small subarrays.
- Therefore, when the current subarray size is less than or equal to k,
  use insertion sort instead of continuing recursive merge sort.

Input array:
[39, 9, 81, 45, 90, 27, 72, 18]

Expected sorted output:
[9, 18, 27, 39, 45, 72, 81, 90]

Students need to complete:

1. insertionSort
2. merge
3. hybridMergeSort
*/

/*
Print the array.
Do not modify this function.
*/
void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);

        if (i < size - 1) {
            printf(" ");
        }
    }
    printf("]\n");
}

/*
Check whether the array is sorted.
Do not modify this function.
*/
int isSorted(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        if (arr[i - 1] > arr[i]) {
            return 0;
        }
    }
    return 1;
}

/*
Sort arr[left...right] using insertion sort.
*/
void insertionSort(int arr[], int left, int right) {
    // TODO: implement insertion sort for arr[left...right]
    for(int i = left; i <= right; i += 1){
      int j = i;
      while(j > left && arr[j-1] > arr[j]){
        int temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
        j -= 1;
      }  
    }
}

/*
Merge two sorted subarrays into one sorted subarray.
*/
void merge(int arr[], int left, int mid, int right) {
    // TODO: implement merge operation
    int *array = malloc((right - left + 1) * sizeof(int));
    int p1 = left;
    int p2 = mid+1;
    for(int i = 0; i < (right-left+1); i += 1){
        if(p1 > mid){
            array[i] = arr[p2];
            p2 += 1;
        } else if(p2 > right){
            array[i] = arr[p1];
            p1 += 1;
        }else{
            if(arr[p1] < arr[p2]){
                array[i] = arr[p1];
                p1 += 1;
            }else{
                array[i] = arr[p2];
                p2 += 1;
            }
        }
    }
    int base = left;
    for(int i = 0; i < (right-left+1); i += 1){
        arr[base] = array[i];
        base += 1;
    }
    free(array);
}

/*
Hybrid merge sort.
*/
void hybridMergeSort(int arr[], int left, int right, int k) {
    // TODO: implement hybrid merge sort
    if(left < right){
        int m = (left + right) / 2;
        if((right - left) + 1 <= k){
            insertionSort(arr, left, right);
        }else{
            hybridMergeSort(arr, left, m, k);
            hybridMergeSort(arr, m+1, right, k);
            merge(arr,left,m,right);
        }     
    }
}

int main() {
    int arr[] = {39, 9, 81, 45, 90, 27, 72, 18};
    int size = sizeof(arr) / sizeof(arr[0]);

    /*
    k is the threshold.

    When the current subarray size is less than or equal to k,
    insertion sort should be used.

    You may change k to test different behaviors.
    */
    int k = 3;

    printf("Original array:\n");
    printArray(arr, size);

    hybridMergeSort(arr, 0, size - 1, k);

    printf("Sorted array:\n");
    printArray(arr, size);

    if (isSorted(arr, size)) {
        printf("Result: PASS\n");
    } else {
        printf("Result: FAIL\n");
    }

    return 0;
}