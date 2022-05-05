class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
  

//         Time Complexity: O(n*m)
//         Space Complexity : O(n+m)
        // int  n = matrix.size();
        // int m = matrix[0].size();
        
//         vector<int> row(n,1);
//         vector<int> column(m,1);
        
//         for(int i =0;i < n; i++){
//             for(int j =0; j < m; j++){
//                 if(matrix[i][j]==0){
//                     row[i]=0;
//                     column[j]=0;
//                 }
//             }
//         }
//         for(int i =0;i < n; i++){
//             for(int j = 0;j < m; j++){
//                 if(row[i]==0 or column[j]==0){
//                     matrix[i][j]=0;
//                 }
//             }
//         }
        
//         Without using extra space 
        
       
// bool firstrow = false;
//         bool firstcol = false;
        
//         int n = matrix.size();
//         int m = matrix[0].size();
        
//         for(int i =0;i < n; i++){
//             for(int j =0; j < m; j++){
//                 if(matrix[i][j]==0){
//                     if(i == 0) firstrow = true;
//                     if(j == 0) firstcol = true;
                
//                     matrix[i][0]=0;
//                     matrix[0][j]=0;
//                 }
//             }
//         }
        
//         for(int i =1; i < n; i++){
//             for(int j =1; j < m; j++){
//                 if(matrix[i][0]==0 || matrix[0][j]==0){
//                     matrix[i][j]=0;
//                 }
//             }
//         }
//         if(firstrow){
//             for(int i = 0; i < m; i++){
//                 matrix[i][0]=0;
//             }
//         }
        
//         if(firstcol){
//             for(int i = 0; i < n; i++){
//                 matrix[0][i]=0;
//             }
//         }
        
        
              
    }
};
