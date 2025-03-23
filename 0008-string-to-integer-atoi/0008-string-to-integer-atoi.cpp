class Solution {
public:
    int myAtoi(string s) {
        int start=0;
        bool isNegative=false;
        int ans=0;
        while(s[start]==' '){
            start++;
        }
        if(s[start]=='-'){
            isNegative=true;
            start++;
        }else if(s[start]=='+'){
            start++;
        }
        while(s[start]=='0') start++;
        for(int i=start;i<s.size();i++){
            if(s[i]>='0' && s[i]<='9'){
                ans*=10;
                ans+=(s[i]-'0');
            }else break;
        }
        return (isNegative) ? -ans : ans; 
    }
};