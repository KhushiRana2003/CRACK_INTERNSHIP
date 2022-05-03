// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

// Time Complexity : O(n)
// Space Complexity : O(n)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        for(int i =0;i < nums.size(); i++){
            mp[nums[i]]++;
        }
        int mn = INT_MAX;
        int x;
        for(auto& i : mp){
            if(i.second == 1){
                x = i.first;
            }
        }
         return x;
    }
};

