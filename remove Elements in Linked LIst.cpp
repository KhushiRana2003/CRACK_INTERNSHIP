class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
//         ListNode* prev = NULL;
//         // ListNode* hc = new ListNode();
//         ListNode* curr = head;
//         if(head == NULL){
//             return NULL;
//         }
//         if(head->next == NULL){
//             if(head->val == val){
//                 return NULL;
//             }
//             else{
//                 return head;
//             }
//         }
//         while(curr != NULL){
//             curr=curr->next;
            
//             if(curr->val == val){
//                 prev->next = curr->next;
//                 prev = curr;
//             }
//             prev = prev->next;
//         }
//        return prev;
        ListNode* hc = new ListNode();
        hc -> next = head;
        ListNode* cur = hc;
        
        while (cur -> next)
        {
            if (cur -> next -> val == val) cur -> next = cur -> next -> next;
            else cur = cur -> next;
        }
        return hc -> next;
    }
    
};
