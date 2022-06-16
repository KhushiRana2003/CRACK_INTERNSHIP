// using python

class Solution:
    def longestPalindrome(self, s: str) -> str:
        start=0
        maxLen=1
        for i in range(1,len(s)):
            l=i-1
            r=i
            print(l,r)
            while l>=0 and r<len(s) and s[l]==s[r]:
                if r-l+1 > maxLen:
                    maxLen=r-l+1
                    start=l
                l-=1
                r+=1
            l=i-1
            r=i+1
            while l>=0 and r<len(s) and s[l]==s[r]:
                if r-l+1 > maxLen:
                    maxLen=r-l+1
                    start=l
                l-=1
                r+=1
                
        return s[start:start+maxLen]
