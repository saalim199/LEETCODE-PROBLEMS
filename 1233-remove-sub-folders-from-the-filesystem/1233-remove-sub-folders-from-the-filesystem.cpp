class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        vector<string> res;
        for(auto f:folder){
            if(res.size()==0){
                res.push_back(f);
                continue;
            }
            string prev=res.back();
            if(f.find(prev)==0 && f.size()>prev.size() && f[prev.size()]=='/') continue;
            else res.push_back(f);
        }
        return res;
    }
};