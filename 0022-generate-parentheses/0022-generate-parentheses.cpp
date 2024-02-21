class Solution {
public:
    void PC(char s[],int o, int c, int i, int n, vector<string>& res) {
        if (c == n) {
            res.push_back(s);
            return;
        } else {
            if (o > c) {
                s[i] = ')';
                PC(s,o, c + 1, i + 1, n, res);
            }
            if (o < n) {
                s[i] = '(';
                PC(s,o + 1, c, i + 1, n, res);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        if(n<=0) return {""};
        if(n==1) return {"()"};
        vector<string> res;
        char s[100];
        PC(s, 0, 0, 0, n, res);
        return res;
    }
};