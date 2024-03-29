class Solution {
public:
    int minimumLength(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
                while(i<=j && s[i]==s[i-1]){
                    i++;
                }
                while(i<=j && s[j]==s[j+1]){
                    j--;
                }
            }else{
                return j-i+1;
            }
        }
        return j-i+1;
    }
};