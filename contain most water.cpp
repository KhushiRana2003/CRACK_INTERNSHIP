class Solution {
public:
    int maxArea(vector<int>& height) {
        int j , i;
        int mx = INT_MIN;
        
        j = height.size()-1;
        i = 0;
        int area;
        
        while(i < j){
            if(height[i] < height[j]){
                area = (j-i)*height[i];
                if(area > mx){
                    mx = area;
                }
                i++;
            }
            else{
                area = (j-i)*height[j];
                if(area > mx){
                    mx = area;
                }
                j--;
            }
        }
        return mx;
    }
};
