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


// Another way to solve

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int res = 0;
		
		//First k elements in our window
        for(int i=0;i<k;i++) res+=cardPoints[i];
        
        int curr=res;
        for(int i=k-1;i>=0;i--) {
			//We remove the last visited element and add the non-visited element from the last
            curr-=cardPoints[i];
            curr+=cardPoints[cardPoints.size()-k+i];
			
            //We check the maximum value any possible combination can give
			res = max(res, curr);
        }
        
        return res;
    }
};
