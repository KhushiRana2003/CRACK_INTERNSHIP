class Solution {
public:
    // int removeDuplicates(vector<int>& nums) {
    //     int l=1;
    //     for(int i=1;i<nums.size();i++){
    //         if(nums[i]!=nums[i-1])
    //         {
    //             nums[l]=nums[i];
    //             l++;
    //         }
    //     }
    //      return l;
    // }
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1)
            return 1;
        int res = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i] != nums[res-1])
                swap(nums[i], nums[res++]);
        }
        return res;
    }
};

//Time complexity : O(n)
// Space complexity : O(1)
