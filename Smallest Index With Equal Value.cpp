class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        // int mn = INT_MIN;
        // vector<int> vec(nums.size());
        for(int i = 0; i < nums.size(); i++){
            int x = i%10;
            if(x == nums[i]){
                return i;
            }
        }
        return -1;
    }
};
