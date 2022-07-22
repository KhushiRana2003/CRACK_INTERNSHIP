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

// 3rd solution
class Solution {
public:
//    using three loops we are going to found 0 then swap it with the starting number now increase.
//     1 ki value khud arrange ho jayegi bcoz 0 se ist m replace kr diya and for 2 last m replace kr diya toh jo hojyega 1 apne ap...
    void sortColors(vector<int>& nums) {
        int i = 0; 
        int j = 0;
        int k = nums.size()-1;
        while(j<=k){
            if(nums[j] == 0){
                swap(nums[i],nums[j]);
                
            i++;
            j++;
            }
            else if(nums[j]==2){
                swap(nums[j],nums[k]);
                k--;
            }
            else{
                j++;
            }
        }
        
        
    }
};
