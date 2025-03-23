class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        for(int i=0;i<strs[0].size();i++){
            char c=strs[0][i];
            bool isCommon=true;
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]!=c){
                    isCommon=false;
                    break;
                }
            }
            if(isCommon){
                ans+=c;
            }else break;
        }
        return ans;
    }
};