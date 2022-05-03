class Solution {
    vector<int> sort(vector<int>nums,int n){
        int temp[n];
        int j =0;
        for(int i =0; i < n; i++){
            if(nums[i]==0){
                temp[j]=nums[i];
                j++;
            }
        }
        for(int i =0; i < n; i++){
            if(nums[i]==1){
                temp[j]=nums[i];
                j++;
            }
        }
        for(int i =0; i < n; i++){
            if(nums[i]==2){
                temp[j]=nums[i];
                j++;
            }
        }
        
        vector<int> v;
        for(int j =0; j < n; j++){
            v.push_back(temp[j]);
        }
        return v;
    }
    
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> x = sort(nums,n);
        
        for(int i =0; i < nums.size(); i++){
            nums[i] = x[i];
        }
    }
    
};
