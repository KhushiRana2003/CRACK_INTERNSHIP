class Solution {
public:
  
  // Time complexity : O(n)
  // Space complexity :O(1)
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for(int i =0; i < nums.size(); i++){
            
            if(nums[i] != 0){
                nums[j++]=nums[i];
                
            }
        }
      
      for(int i = j; i < nums.size(); i++){
        nums[i]=0;
      }
        
    }
};
