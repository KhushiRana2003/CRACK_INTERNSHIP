# include <stack>
bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(int i = 0; i < s.length(); i++){
        char ch = s[i];
        if(ch == '(' || ch =='+' || ch == '-' || ch == '*' || ch =='/'){
            st.push(ch);
        }
        else{
//             ch is a closing brackets or lowercase letters
            if(ch == ')' ){
//                 check is there any operator in between or not
                bool red = true;
                while(st.top() != '('){
                    char top = st.top();
                    if(top =='+' || top == '-' || top == '*' || top =='/' ){
                        red = false;
                    }
                    st.pop();
                }
                if(red == true){
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;
}
