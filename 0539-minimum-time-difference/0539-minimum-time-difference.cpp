class Solution {
public:
    int findMinDifference(vector<string>& tp) {
        int n=tp.size();
        vector<int> mins;
        for(int i=0;i<n;i++){
            int h=stoi(tp[i].substr(0,3));
            int m=stoi(tp[i].substr(3));
            mins.push_back(h*60+m);
        }
        sort(mins.begin(),mins.end());
        int mini=INT_MAX;
        for(int i=0;i<n-1;i++){
            mini=min(mini,mins[i+1]-mins[i]);
        }
        for(auto it:mins){
            cout<<it<<endl;
        }
        mini=min(mini,24*60-mins.back()+mins.front());
        return mini;
    }
};