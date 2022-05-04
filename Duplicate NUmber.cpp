class Solution {
public:
    int findDuplicate(vector<int>& nums) {
//         time complexity : O(nlogn)
//         space complexity : O(1)
        
//         sort(nums.begin(),nums.end());
        
//         for(int i =0; i < nums.size(); i++){
//             if(nums[i] == nums[i+1]){
//                 return nums[i];
//             }
//         }
//         return -1;
        
        
//         Time Complexity : O(n)
//         Space Complexity : O(n)
        unordered_map<int,int> mp;
        for(int i =0;i < nums.size(); i++){
            mp[nums[i]]++;
        }
        int y;
        for(auto& x: mp){
            if(x.second >= 2){
                y = x.first;
            }
        }
        return y;
    }
};
