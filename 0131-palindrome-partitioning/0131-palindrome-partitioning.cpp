class Solution {
public:
    void solve(string s, int i, vector<string> ds, vector<vector<string>> &ans){
        if(i==s.size()){
            ans.push_back(ds);
            return;
        }
        for(int j=i;j<s.size();j++){
            if(isPalindrome(s,i,j)){
                string t=s.substr(i,j-i+1);
                ds.push_back(t);
                solve(s,j+1,ds,ans);
                ds.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int st, int e){
        while(st<e){
            if(s[st]!=s[e]) return false;
            st++;
            e--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        solve(s,0,{},ans);
        return ans;
    }
};