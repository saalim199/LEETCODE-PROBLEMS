class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> last;
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            last[s[i]]=i;
        }
        int k=0;
        int j=0;
        for(int i=0;i<s.size();i++){
            if(last[s[i]]>j){
                j=last[s[i]];
            }
            if(i==j){
                ans.push_back(i-k+1);
                k=i+1;
            }
        }
        return ans;
    }
};