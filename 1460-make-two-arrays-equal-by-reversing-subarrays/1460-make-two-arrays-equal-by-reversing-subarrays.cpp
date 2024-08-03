class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        int tSize=target.size();
        int aSize=arr.size();
        if(tSize!=aSize) return 0;
        sort(target.begin(),target.end());
        sort(arr.begin(),arr.end());
        for(int i=0;i<tSize;i++){
            if(arr[i]!=target[i]) return 0;
        }
        return 1;
    }
};