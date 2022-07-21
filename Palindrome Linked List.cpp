// Ist solution:
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        
        ListNode* temp = head;
        while(temp != NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        
        int i = 0;
        int j = v.size()-1;
        
        while(i < j){
            if(v[i] != v[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

// 2nd solution
class Solution {
		public:
			bool isPalindrome(ListNode* head) 
			{
				if(head->next==NULL)
					return true;

				ListNode* mid=middleOfList(head);
				ListNode* list2=reverseList(mid->next);
				while(head!=NULL && list2!=NULL)
				{
					if(head->val!=list2->val)
						return false;
					head=head->next;
					list2=list2->next;
				}
				return true;
			}

			ListNode* reverseList(ListNode* head)
			{
				if(head==NULL || head->next==NULL)
					return head;
				ListNode* pre=NULL;
				ListNode* curr=head;
				ListNode* temp_next;
				while(curr!=NULL)
				{
					temp_next=curr->next;
					curr->next=pre;
					pre=curr;
					curr=temp_next;
				}
				return pre;
			}
			ListNode* middleOfList(ListNode* head)
			{
				if(head==NULL || head->next==NULL)
					return head;
				ListNode* fast=head;
				ListNode* slow=head;
				while(fast->next!=NULL && fast->next->next!=NULL)
				{
					slow=slow->next;
					fast=fast->next->next;
				}
				return slow;
			}
		};
