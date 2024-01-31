class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> res(t.size());
        stack<int> st;
        for(int i=0;i<t.size();i++){
            while(!st.empty() && t[st.top()]<t[i]){
                res[st.top()]=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};