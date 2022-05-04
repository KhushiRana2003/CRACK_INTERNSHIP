class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
//          Time Complexity: O(n);
//         Space Complexity : O(n);
        // unordered_map<int,int> mp;
        // int count=0;
        // for(int i = 0;i < nums.size(); i++){
        //     int diff = k - nums[i];
        //     if(mp[diff]>0){
        //         count++;
        //         mp[diff]--;
        //     }
        //     else{
        //         mp[nums[i]]++;
        //     }
        // }
        // return count;
        
        
//         Time Complexity: O(nlogn);
//         Space Complexity : O(1);
        sort(nums.begin(),nums.end());
        
        int i =0;
        int count=0;
        int j = nums.size()-1;
        while(i < j){
            if(nums[i]+nums[j]>k){
                j--;
                continue;
            }
            if(nums[i]+nums[j]==k){
                count++;
                i++;
                j--;
                continue;
            }
            if(nums[i]+nums[j]<k){
                i++;
                continue;
            }
        }
        return count;
    }
};
