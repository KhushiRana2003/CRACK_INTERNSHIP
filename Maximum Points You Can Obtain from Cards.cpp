// BY using sliding Window Techniques.
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int score=0, total=0;
        if(k==0)
            return 0;
        
        for(int i=0; i<cardPoints.size(); i++)
            total += cardPoints[i]; 
        if(k == cardPoints.size())
            return total;
        
        int low=0, high=cardPoints.size()-k;
        for(int i=low; i<high; i++)
            score += cardPoints[i];
        score = total - score;

        int ans=score;
        while(high<cardPoints.size()){
            score = score - cardPoints[high++] + cardPoints[low++];
            ans = max(ans, score);
        }
        
        return ans;
    }
};
