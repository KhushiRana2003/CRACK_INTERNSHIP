// public class Solution {
//     public int kInversePairs(int n, int k) {
//         int[][] dp = new int[n + 1][k + 1];
//         for (int i = 1; i <= n; i++) {
//             for (int j = 0; j <= k; j++) {
//                 if (j == 0)
//                     dp[i][j] = 1;
//                 else {
//                     for (int p = 0; p <= Math.min(j, i - 1); p++)
//                         dp[i][j] = (dp[i][j] + dp[i - 1][j - p]) % 1000000007;
//                 }
//             }
//         }
//         return dp[n][k];
//     }
// }

public class Solution {
    public int kInversePairs(int n, int k) {
        int[][] dp = new int[n + 1][k + 1];
        int M = 1000000007;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j == 0)
                    dp[i][j] = 1;
                else {
                    int val = (dp[i - 1][j] + M - ((j - i) >= 0 ? dp[i - 1][j - i] : 0)) % M;
                    dp[i][j] = (dp[i][j - 1] + val) % M;
                }
            }
        }
        return ((dp[n][k] + M - (k > 0 ? dp[n][k - 1] : 0)) % M);
    }
}
