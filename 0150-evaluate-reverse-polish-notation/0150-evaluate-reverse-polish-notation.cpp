class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto w:tokens){
            if(w=="+"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=a+b;
                st.push(c);
            }else if(w=="-"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=b-a;
                st.push(c);
            }else if(w=="*"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=b*a;
                st.push(c);
            }else if(w=="/"){
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int c=b/a;
                st.push(c);
            }else{
                int a=stoi(w);
                st.push(a);
            }
        }
        return st.top();
    }
};