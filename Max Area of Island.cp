// class Solution {
// public:
//     int maxAreaOfIsland(vector<vector<int>>& grid) {
        
//         int mx = INT_MIN;
//         int m = grid.size();
//         int n = grid[0].size();
        
//         for(int i = 0; i < m; i++){
//             int count = 1;
//             for(int j = 0; j < n; j++){
// //                 check if value is 1
                
//                 if(grid[i][j] == 1){
//                     count_isLand(grid,i,j,count);
//                 }
//                 mx = max(mx,count);
//             }
//         }
//         return mx;
//     }
    
//     int count_isLand(vector<vector<int>>& grid,int i, int j, int& count){
// //         check if it is within bounds
//         if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()){
//             return 0;
//         }
//         if(grid[i][j] == 0) //useless neighbour
//             return 0;
        
//         grid[i][j] = 0;
        
// //         call the neighbour & see if they are helpful
        
//         if(count_isLand(grid,i-1,j,count)) count++; //above neighbour
        
//         if(count_isLand(grid,i+!1,j,count)) count++; //below neighbour
        
//         if(count_isLand(grid,i,j-1,count)) count++; //left neighbour
        
//         if(count_isLand(grid,i,j+1,count)) count++; //right neighbour
        
//         return 1;
//     }
    
// };

class Solution {
public:
    
    int utility(vector<vector<int>>& grid, int i, int j)
    {
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size())
            return 0;
        if(grid[i][j]==0)
            return 0;
       
        grid[i][j]=0;
         
            
        return (1+ utility(grid, i+1, j) + utility(grid, i, j+1) + utility(grid, i-1, j) + utility(grid, i, j-1));
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0, x =0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(grid[i][j])
                    x = utility(grid, i, j);
                
                ans = max(ans, x);
            }
        return ans;
    }
};
