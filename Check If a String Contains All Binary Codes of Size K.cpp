class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> st;
        for(int i =0; i < s.length(); i++){
            string q ="";
            for(int j = i; j < s.length(); j++){
                q += s[j];
                if(q.length() == k){
                    st.insert(q);
                    break;
                }
            }
        }
        int count= 0;
        for (auto it = st.begin(); it !=st.end(); it++){
            count++;
            // cout<<" "<<*it;
        }
        int x = pow(2,k);
        if(count == x){
            return true;
        }
        return false;
    }
};
