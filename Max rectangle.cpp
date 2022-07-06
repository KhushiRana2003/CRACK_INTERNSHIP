class Solution{
    private:
    vector<int> nextSmallerElement(int* ht, int n){
        stack<int> s;
        s.push(-1);
        
        vector<int> ans(n);
        
        for(int i = n-1; i >= 0; i--){
            int curr = ht[i];
            while(s.top() != -1 && ht[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(int* ht, int n){
        stack<int> s;
        s.push(-1);
        
        vector<int> ans(n);
        
        for(int i = 0; i < n; i++){
            int curr = ht[i];
            while(s.top() != -1 && ht[s.top()] >= curr){
                s.pop();
            }
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    
    int largestRectangleArea(int* heights,int n) {
        // int n= heights.size();
        vector<int> next(n);
        
        next = nextSmallerElement(heights,n);
        
        vector<int> prev(n);
        prev = prevSmallerElement(heights,n);
        
        int area = INT_MIN;
        for(int i = 0; i < n; i++){
            int l = heights[i];
            
            if(next[i] == -1){ 
                //when all element are equal then we gonna push -1 everywhere so 
                next[i] = n;
            }
            int b = next[i] - prev[i] -1;
            int newArea = l*b;
            area = max(area,newArea);
        }
        return area;
    }
  public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // compute area of first row
        int area = largestRectangleArea(M[0],m);
        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                // row update by adding previous row's value
                if(M[i][j] != 0)
                    M[i][j] = M[i][j] + M[i-1][j];
                else
                    M[i][j]=0;
            }
            // entire row is updated now
            area = max(area,largestRectangleArea(M[i],m));
        }
        return area;
    }
        
};
