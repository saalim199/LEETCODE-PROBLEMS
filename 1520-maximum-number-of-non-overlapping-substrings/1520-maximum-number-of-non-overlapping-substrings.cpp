class Solution {
public:
    int check(string s,int i,unordered_map<char,int> left, unordered_map<char,int> right){
        int r=right[s[i]];
        for(int j=i;j<=r;j++){
            if(left[s[j]]<i) return -1;
            r=max(right[s[j]],r);
        }
        return r;
    }
    vector<string> maxNumOfSubstrings(string s) {
        unordered_map<char,int> left,right;
        vector<string> res;
        for(int i=0,j=s.size()-1;i<s.size(),j>=0;i++,j--){
            if(left.find(s[i])==left.end()){
                left[s[i]]=i;
            }
            if(right.find(s[j])==right.end()){
                right[s[j]]=j;
            }
        }
        int end=-1;
        for(int i=0;i<s.size();i++){
            if(i==left[s[i]]){
                int new_right=check(s,i,left,right);
                if(new_right!=-1){
                    if(i>end){
                        res.push_back("");
                    }
                    end=new_right;
                    res.back()=s.substr(i,end-i+1);
                }
            }
        }
        return res;
    }
};