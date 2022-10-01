// memoization 
class Solution {
public:
vector<int> dp;
    int numDecodings(string s) {
        dp.resize(s.size());
        dp.assign(s.size(), -1);
        return nways(0,s);
    }

    int nways(int i, string s){
        if( i>= s.size())
            return 1;
        
        else if(s[i] == '0')
            return 0;
        
        else if(i == s.size()-1)
            return 1;
        
        else if(dp[i] != -1)
            return dp[i];
        else if(s[i] == '1' || (s[i] == '2' && (s[i+1] >= 48 && s[i+1] <= 54))){
            return dp[i] = nways(i+1,s) + nways(i+2,s);
        }

        else return dp[i] = nways(i+1,s);

    }

};

// itertive approach 

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1);
        if(s.size() == 0 || s[0] =='0')
            return 0;

        dp[0] = 1;
        dp[1] = 1;
        int n = s.size();
        for(int i = 2; i <= n; i++){
            if(s[i-1] >= '1' && s[i-1] <= '9'){
                dp[i] = dp[i-1];
            }
            if(s[i-2] == '1'){
                dp[i] += dp[i-2];
            }
            else if(s[i-2] == '2' && (s[i-1] >= '0' && s[i-1] <= '6')){
                dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};
