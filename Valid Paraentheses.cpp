class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char,int> paren = {{'(', 1}, {')', 1},{'{', 2},{'}', 2},{'[', 3},{']', 3}};

        for(int i=0; i<s.length(); i++){
            char ch = s.at(i);

            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else if(!st.empty() && paren[ch] == paren[st.top()]){
                st.pop();
            }
            else
                return false;
        }
        
        return st.empty();
    }
};
