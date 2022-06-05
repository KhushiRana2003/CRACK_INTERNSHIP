class Solution {
public:
    int doswap(int num, string nums, int idx, int idxj) {
        swap(nums[idx], nums[idxj]);
        
        int p = 1;
        int nnum = 0;
        for(int i=nums.size()-1; i>=0; i--) {
            nnum = nnum + p*(nums[i] - '0');
            p = p *10;
        }
        
        return nnum;
    }
    int maximumSwap(int num) {
        string s = to_string(num);
        
        vector<int> d = vector(10, -1);
        
        for(int i=0; i<s.size(); i++) {
            d[s[i]-'0'] = i;
        }
        
        int ans = num;
        bool swapped  = false;
        for(int i=0; i<s.size(); i++) {
            int digit = s[i] - '0';
            for(int j=9; j>digit; j--) {
                if(i < d[j]) {
                    swapped = true;
                    ans = doswap(num, s, i, d[j]);
                    break; 
                }
            }
            if(swapped) {
                break;
            }
        }
        
        return ans;
    }
};
