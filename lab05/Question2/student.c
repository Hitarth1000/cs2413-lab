/*
Question 2: Kth Largest Element in an Array

Description:
Given an integer array nums and an integer k, return the kth largest
element in the array.

Note that it is the kth largest element in sorted order, not the kth
distinct element.

For this lab, you should solve the problem using a heap-based idea.

Function:
int findKthLargest(int* nums, int numsSize, int k);

Notes:
- You may assume 1 <= k <= numsSize.
- Repeated values still count.
- A min-heap of size k is a good way to solve this efficiently.

Example 1:
Input:  nums = [3, 2, 1, 5, 6, 4], k = 2
Output: 5

Example 2:
Input:  nums = [3, 2, 3, 1, 2, 4, 5, 5, 6], k = 4
Output: 4

Hint:
Keep only the k largest elements seen so far in a min-heap.
The root of that heap will be the kth largest element.
*/

#include <stdlib.h>

/*
Optional helper function declarations.

You may use them, modify them, or remove them if you prefer your own design.
*/
static void swap(int* a, int* b);
static void heapifyUp(int* heap, int index);
static void heapifyDown(int* heap, int size, int index);

/*
Return the kth largest element in nums.
*/
int findKthLargest(int* nums, int numsSize, int k) {
    /* Write your code here */
    int* heap = malloc(sizeof(int) * k);
    for(int i = 0; i < k; i ++){
        heap[i] = nums[i];
        heapifyUp(heap, i);
    }
    for(int i = k; i < numsSize; i ++){
        if(nums[i] > heap[0]){
            heap[0] = nums[i];
            heapifyDown(heap, k, 0);
        }
    }
    int res = heap[0];
    free(heap);
    return res;
}

/*
Optional helper: swap two integers.
*/
static void swap(int* a, int* b) {
    /* Write your code here if you use this helper */
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
Optional helper: restore min-heap order from a node upward.
*/
static void heapifyUp(int* heap, int index) {
    /* Write your code here if you use this helper */
    while(index > 0){
        if(heap[(index-1)/2] > heap[index]){
            swap(&heap[(index-1)/2], &heap[index]);
            index = (index-1)/2;
        }else{
            break;
        }
    }
}

/*
Optional helper: restore min-heap order from a node downward.
*/
static void heapifyDown(int* heap, int size, int index) {
    /* Write your code here if you use this helper */
    while(1){
        int left = index * 2 + 1;
        int right = index * 2 + 2;
        int smallest = index;

        if(left < size && heap[left] < heap[smallest]){
            smallest = left;
        }
        if(right < size && heap[right] < heap[smallest]){
            smallest = right;
        }
        if(index == smallest){
            break;
        }
        swap(&heap[smallest], &heap[index]);
        index = smallest;
    }
    return;
}