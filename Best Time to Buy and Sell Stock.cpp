class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minsoFar = prices[0];
        int maxprofit = 0;
        for(int i = 0;i < prices.size(); i++){
            minsoFar = min(minsoFar,prices[i]);
            int profit = prices[i]-minsoFar;
            maxprofit = max(maxprofit,profit);
        }
        return maxprofit;
    }
};

// Time Complexity : O(n)
// SPace Complexity : O(1)
