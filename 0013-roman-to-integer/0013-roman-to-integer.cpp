class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> mp = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int num=0;
        num+=mp[s[0]];
        for(int i=1;i<s.size();i++){
            if(mp[s[i-1]]<mp[s[i]]){
                num+=mp[s[i]]-(2*mp[s[i-1]]);
            }else{
                num+=mp[s[i]];
            }
        }
        return num;
    }
};