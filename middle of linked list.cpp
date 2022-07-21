class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector <ListNode*> A={head};
        
        while(A.back()->next != NULL){
            A.push_back(A.back()->next);
            
        }
         return A[A.size()/2];
    }
};

// 2nd Solution
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        
        if(head!= NULL){
            while(temp2 != NULL && temp2->next != NULL){
                temp2 = temp2->next->next;
                temp1 = temp1->next;
            }
        }
        return temp1;
    }
};
