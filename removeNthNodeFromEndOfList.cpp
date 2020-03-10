/**
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/

//cpp Solution : 
 ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head;
        ListNode *second = head; 
        for (int i = 0; i < n; i++) 
        { 
            if (second->next == NULL)  
            { 
                if (i == n - 1) 
                    head = head->next; 
                return head; 
            } 
            second = second->next; 
        } 
         while (second->next != NULL) 
        { 
            first = first->next; 
            second = second->next; 
        } 
        first->next = first->next->next; 
        return head; 
    } 
	

//java Solution : 
