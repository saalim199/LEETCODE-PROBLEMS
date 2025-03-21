class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(s[i]==')'){
                if(!st.empty() && st.top()=='(') {
                    st.pop();
                    continue;
                }
                else return false;
            }else if(s[i]==']'){
                if(!st.empty() && st.top()=='[') {
                    st.pop();
                    continue;
                }
                else return false;
            }else if(s[i]=='}'){
                if(!st.empty() && st.top()=='{'){
                    st.pop();
                    continue;
                }else return false;
            }else{
                st.push(s[i]);
            }
        }
        if(st.empty()) return true;
        return false;
    }
};