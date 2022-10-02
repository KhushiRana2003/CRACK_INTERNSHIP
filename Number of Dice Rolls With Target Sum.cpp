class Solution {
public:
// recursive solution
    int solve(int n, int k, int target){
        // base case
        if(target < 0){
            return 0;
        }
        if(n == 0 && target != 0){
            return 0;
        }
        if(n != 0 && target == 0){
            return 0;
        }
        
        if(target == 0 && n == 0){
            return 1;
        }

        long long ans = 0;
        for(int i = 1; i <= k; i++){
            ans += numRollsToTarget(n-1, k, target-i);
        }
        return ans;
    }

    int solveMemo(int n, int k, int target, vector<vector<int>> &dp){
        // base case
        if(target < 0){
            return 0;
        }

        if(n == 0 && target != 0){
            return 0;
        }

        if(n != 0 && target == 0){
            return 0;
        }
        
        if(target == 0 && n == 0){
            return 1;
        }

        if(dp[n][target] != -1){
            return dp[n][target];
        }

        long long ans = 0;
        for(int i = 1; i <= k; i++){
            ans += solveMemo(n-1, k, target-i, dp);
            ans= ans%1000000007;
        }
        return dp[n][target] = ans;
    }

    int solveTab(int dice, int faces, int target){
        vector<vector<int>> dp(dice+1, vector<int>(target+1, 0));
        dp[0][0] = 1;

        for(int d = 1; d <= dice; d++){
            for(int t = 1; t <= target; t++){
                long long ans = 0;
                for(int i = 1; i <= faces; i++){
                    if(t-i >= 0)
                        ans = ans+dp[dice-1][target-i];
                        ans= ans%1000000007;
                }
                dp[d][t] = ans;
            }
        }
        return dp[dice][target];
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
        // return solveMemo(n,k,target,dp);
        return solveTab(n, k, target);
    }
};
