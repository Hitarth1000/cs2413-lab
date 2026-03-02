// Question2/student.c
// ------------------------------------------------------------
// CS Lab03 - Swap Nodes in Pairs 
//
// TODO:
//   Implement swapPairs(head) to swap every two adjacent nodes.
//
// Rules:
// - Do not allocate new nodes.
// - Do not swap values; swap nodes (rewire pointers).
// - Return the new head pointer.
// ------------------------------------------------------------
#include "student.h"

struct ListNode* swapPairs(struct ListNode* head) {
      // TODO: implement
      if(head == NULL || head->next == NULL){
            return head;
      }
      
      struct ListNode start;
      start.next = head;
      struct ListNode* prev = &start;
      struct ListNode* a = NULL;
      struct ListNode* b = NULL;
      while(prev->next != NULL && prev->next->next != NULL){
            a = prev->next;
            b = prev->next->next;
            a->next = b->next;
            b->next = a;
            prev->next = b;
            prev = a;
      }
      return start.next;
}