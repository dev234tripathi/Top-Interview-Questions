/**
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

//cpp Solution :
 ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         if(l1==NULL)
        return l2;
    else if(l2==NULL)
        return l1;
    
	//starting node
    ListNode *head = new ListNode(0);
    ListNode *result=head;
    
    while(l1!=NULL && l2!=NULL)
    {   
        if(l1->val <= l2->val)
        {
            head->next=l1;
            l1=l1->next;
        }            
        else
        {
            head->next=l2;
            l2=l2->next;
        }
        head=head->next;
    }
    
    if(l1==NULL)
        head->next=l2;
    else if(l2==NULL)
        head->next=l1;
    
    return result->next;
    }
	
/**

java Solution: recursive 

public ListNode mergeTwoLists(ListNode l1, ListNode l2){
		if(l1 == null) return l2;
		if(l2 == null) return l1;
		if(l1.val < l2.val){
			l1.next = mergeTwoLists(l1.next, l2);
			return l1;
		} else{
			l2.next = mergeTwoLists(l1, l2.next);
			return l2;
		}
}

*/