class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res=head->val;
        while(head->next != NULL){
            res=res*2+head->next->val;
            head=head->next;
        }
        
        return res;
    }
};
