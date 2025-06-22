class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        string temp="";
        int cnt=0;
        for(int i=0;i<s.size();i++){
            cnt++;
            temp+=s[i];
            if(cnt==k){
                res.push_back(temp);
                cnt=0;
                temp="";
            }
        }
        if(cnt!=0){
            while(cnt!=k){
                temp+=fill;
                cnt++;
            }
            res.push_back(temp);
        }
        return res;
    }
};