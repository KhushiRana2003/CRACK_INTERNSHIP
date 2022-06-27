class Solution {
public:
    int minPartitions(string n) {
        int ans = 0;
        for(char x:n){
//             ascii value for character varies between 48 to 57
            
            int curr = x-48; //digit=>3=>ascii=>51 -> 51-48 =3 
            ans = max(ans,curr);
            
        }
        return ans;
    }
};
