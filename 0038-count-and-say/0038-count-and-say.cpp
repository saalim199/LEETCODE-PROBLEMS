class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        for (int i = 1; i < n; i++) {
            string temp="";
            for(int j=0;j<s.size();j++){
                int cnt=1;
                while(j+1<s.size() && s[j]==s[j+1]){
                    cnt++;
                    j++;
                }
                temp+=to_string(cnt);
                temp+=s[j];
            }
            s=temp;
        }
        return s;
    }
};