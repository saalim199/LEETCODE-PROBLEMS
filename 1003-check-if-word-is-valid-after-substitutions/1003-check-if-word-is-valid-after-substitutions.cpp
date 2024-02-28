class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto w:s){
            if(w=='a' || w=='b') st.push(w);
            else{
                if(st.size()>=2){
                    if(st.top()!='b') return false;
                    st.pop();
                    if(st.top()!='a') return false;
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        if(st.size()==0) return true;
        else return false;
    }
};