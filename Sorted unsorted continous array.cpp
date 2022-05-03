// leetcode 3rd may streak....
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
//         time complexity : O(nlogn)
//         space complexity : O(n)
//         vector<int> v;
//         for(int i = 0;i < nums.size(); i++){
//             v.push_back(nums[i]);
//         }
//         sort(v.begin(),v.end());
        
//         int start= v.size()-1;
//         int end = 0;
//         if(start == end){
//             return 0;
//         }
//         for(int i =0; i < v.size(); i++){
//             if(v[i] != nums[i]){
//             start = min(start,i);
//             end = max(end,i);
//             }
            
//         }
        
        
//        return (end-start >= 0 ? end-start+1:0);
        
        
//         time complexity : O(n)
//         space complexity : O(1)
        int n=nums.size();
        int i=0,j=n-1;
        int first=-1;
        for(;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                first=i;
                break;
            }
        }
        if(first==-1) return 0;
        int second=0;
        for(;j>0;j--){
            if(nums[j]<nums[j-1]){
                second=j;
                break;
            }
        }
        int temp=i;
        int miin=INT_MAX;
        int maxi=INT_MIN;
        for(;temp<=j;temp++){
            miin=min(nums[temp],miin);
            maxi=max(maxi,nums[temp]);
        }
        for(int k=0;k<i;k++){
            if(nums[k]>miin){
                first=k;
                break;
        }
        }
        int r=j+1;
        for(int r=0;r<n;r++){
            if(nums[r]<maxi){
            second=r;
            }
        }
        return second-first+1;
        
    }
};
