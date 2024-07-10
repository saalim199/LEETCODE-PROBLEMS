class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        for(int i=1;i<n;i++){
                string temp="";
            for(int j=0;j<s.size();j++){
                int cnt=1;
                char ch=s[j];
                while((j+1)<s.size() && s[j]==s[j+1]){
                    cnt++;
                    j++;
                }
                string a =to_string(cnt);
                temp+=a;
                temp.push_back(ch);
            }
            s=temp;
            cout<<s<<endl;
        }
        return s;
    }
};