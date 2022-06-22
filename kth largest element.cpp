// Time Complexity : O(nlogn)
// Space Complexity : O(1)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()==1){
            return nums[0];
        }
        int n = nums.size();
        sort(nums.begin(),nums.end(), greater<int>());
        for(int i = 0; i < nums.size(); i++){
            cout<<nums[i]<<" ";
        }
        int x = nums[k-1];
        return x;
    }
};

// 2nd Approach using priority queue 
