class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if (s.size() == 1)
            return false;
        for (auto a : s) {
            if (a == '(' || a == '[' || a == '{')
                st.push(a);
            else {
                if (st.empty() || (a == ']' && st.top() != '[') ||
                    (a == '}' && st.top() != '{') ||
                    (a == ')' && st.top() != '('))
                    return false;
            st.pop();
            }
        }
        return st.empty();
    }
};