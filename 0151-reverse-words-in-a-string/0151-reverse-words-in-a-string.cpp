class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int n=s.size();
        int j=n-1;
        int i=n-1;
        while(j>=0 && s[j]==' ') {
            i--;
            j--;
        }
        while(j>=0){
            if(s[j]==' ' || j==0){
                cout<<i<<" "<<j<<endl;
                if(j>0) ans+=s.substr(j+1,i-j);
                else ans+=s.substr(j,i-j+1);
                ans+=' ';
                j--;
                while(j>=0 && s[j]==' '){
                    j--;
                }
                i=j;
            }
            else j--;
        }
        ans.pop_back();
        return ans;
    }
};