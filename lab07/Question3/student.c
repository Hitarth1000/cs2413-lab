/*
Question 3: Quick Sort

Description:
Implement quick sort to sort an integer array in ascending order.

Quick sort is a divide-and-conquer algorithm:
1. Choose a pivot element.
2. Partition the array so that elements smaller than or equal to
   the pivot come before it, and elements greater than the pivot
   come after it.
3. Recursively sort the left and right parts.

You should implement:

    void quickSort(int arr[], int size);

You may design your own helper functions.
Suggested helper functions:

    void quickSortHelper(int arr[], int low, int high);
    int partition(int arr[], int low, int high);

For simplicity, you may use the last element as the pivot.

Example:
Input:  [10, 7, 8, 9, 1, 5]
Output: [1, 5, 7, 8, 9, 10]

Notes:
- If the array is empty or has only one element, do nothing.
- The sorting should be done in ascending order.
*/


int partition(int arr[], int low, int high) {
    int piv = low;
    int l = piv;
    int r = high;
    int flag = 0;
    while(l < r){
        if(!flag){
            if(arr[r] < arr[l]){
                int temp = arr[l];
                arr[l] = arr[r];
                arr[r] = temp;
                flag = 1;
                piv = r;
            }else{
                r -= 1;
            }
        }else{
            if(arr[r] < arr[l]){
                int temp = arr[l];
                arr[l] = arr[r];
                arr[r] = temp;
                flag = 0;
                piv = l;
            }else{
                l += 1;
            }
        }
    }
    return piv;
}


void quickSortHelper(int arr[], int low, int high){
    if(low < high){
        int pivit = partition(arr, low, high);
        quickSortHelper(arr, pivit + 1, high);
        quickSortHelper(arr, low, pivit-1);
    }
}



void quickSort(int arr[], int size) {
    // TODO: implement quick sort
    
    quickSortHelper(arr, 0, size-1);
    (void)arr;
    (void)size;
}