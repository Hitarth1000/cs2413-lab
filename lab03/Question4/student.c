// Question4/student.c
// ------------------------------------------------------------
// CS Lab03 - Middle Node of Linked List
//
// TODO:
//   Implement middleNodeValue(head) using fast/slow pointers.
//
// Notes:
// - If even length, return the second middle.
// - Do not allocate new nodes.
// ------------------------------------------------------------

#include "Student.h"

int middleNodeValue(struct ListNode *head) {
    // TODO: implement
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast->next != NULL){
        return slow->next->val;
    }
    else{
        return slow->val;
    }
}