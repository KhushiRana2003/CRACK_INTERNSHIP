class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int n =  numRows;
        
        vector<vector<int>> ans;
        if( n == 1)
        {   
			// edge case just push {1} to ans vec tor
            ans.push_back({1});
        }
        if(n == 2)
        {
			// edge case just push {1}  and {1,1}  ans vec tor
            ans.push_back({1});
            ans.push_back({1,1});
        }
        
        if(n >=3)
        {
			// repeat these prior steps
            ans.push_back({1});
            ans.push_back({1,1});
            
			// an variable which will tell us how many element to put on current row
            int level = 2;
            
            for(int i = 1; i<n-1; ++i)
            {
                vector<int> v;
                for(int j = 0; j<= level; ++j)
                {
					// edges case first element of current row has to be first element of prev row.
                    if(j == 0)
                        v.push_back(ans[i][0]);
                    else if(j == level)
                    {
							// edges case last element of current row has to be last element of prev row.
                        v.push_back(ans[i][level-1]);
                    }
                    else
                    {
                        v.push_back(ans[i][j-1] + ans[i][j]);
                    }    
                }
                ++level;
                ans.push_back(v);
            }
        }
        
        return ans;
    }
};
