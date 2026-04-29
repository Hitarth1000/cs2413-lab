/*
Question 2: Merge Sort

Description:
Implement merge sort to sort an integer array in ascending order.

Merge sort is a divide-and-conquer algorithm:
1. Divide the array into two halves.
2. Recursively sort each half.
3. Merge the two sorted halves into one sorted array.

You should implement:

    void mergeSort(int arr[], int size);

You may design your own helper functions.
Suggested helper functions:

    void mergeSortHelper(int arr[], int left, int right);
    void merge(int arr[], int left, int mid, int right);

Example:
Input:  [38, 27, 43, 3, 9, 82, 10]
Output: [3, 9, 10, 27, 38, 43, 82]

Notes:
- If the array is empty or has only one element, do nothing.
- You may use temporary arrays inside your merge function.
*/

void mergeSortHelper(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

void mergeSort(int arr[], int size) {
    // TODO: implement merge sort
    mergeSortHelper(arr, 0, size-1);
    (void)arr;
    (void)size;
}

void mergeSortHelper(int arr[], int left, int right){
    if(left < right){
        int m = (left + right) / 2;
        mergeSortHelper(arr, left, m);
        mergeSortHelper(arr, m+1, right);
        merge(arr,left,m,right);
    }
    
}

void merge(int arr[], int left, int mid, int right){
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
