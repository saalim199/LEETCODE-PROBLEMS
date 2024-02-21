class Solution {
public:
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    void findS(vector<string> &ans, int i, string digits,string s){
        if(i>=digits.size()){
            ans.push_back(s);
            return;
        }
        string c=mp[digits[i]];
        for(int k=0;k<c.size();k++){
            s+=(c[k]);
            findS(ans,i+1,digits,s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0) return ans;
        string s="";
        findS(ans,0,digits,s);
        return ans;
    }
};