class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        if(nums.size()<3) return {};   //check for base case1
        if(nums[0]>0) return {};       //check for base case2
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) //skipping duplicate elements for i loop
                continue;
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int sum=nums[i];
                sum+=nums[j];
                sum+=nums[k];
                if(sum==0){
                   res.push_back({nums[i],nums[j],nums[k]}); 
                    while(j<k && nums[j]==nums[j+1]) //skipping duplicate elements j loop
                        j++;
                    while(j<k && nums[k]==nums[k-1])  //skipping duplicate elements for k loop
                        k--;
                    j++;
                    k--;
                }   
                else if(sum>0)
                    k--;
                else j++;
            }
        }
        return res;
    }
};
