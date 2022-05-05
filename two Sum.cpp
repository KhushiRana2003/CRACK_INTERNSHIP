class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // vector<int> c;
        // for(int i =0; i < nums.size(); i++){
        //     for(int j = i+1; j < nums.size(); j++){
        //         if(nums[i]+nums[j] == target){
        //             c.push_back(i);
        //             c.push_back(j);
        //             break;
        //         }
        //     }
        // }
        // return c;
        
        
        unordered_map<int,int> mp;
        for(int i =0;i < nums.size(); i++){
            int k = target-nums[i];
            if(mp.count(k) > 0){
                return {mp[k],i};
            }mp[nums[i]]=i;
        }
        return {-1,-1};
    }
};
