class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        string res="";

        for(int i=0;i<s.size();i++){
            if(s[i]!=')'){
                st.push(s[i]);
            }else{
                res="";
                while(st.size()!=0 && st.top()!='('){
                    char ch=st.top();
                    // cout<<ch;
                    st.pop();
                    res.push_back(ch);
                }
                if(st.size()!=0){
                    st.pop();
                }
                for(int j=0;j<res.size();j++){
                    st.push(res[j]);
                }
            }
        }
        res="";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};