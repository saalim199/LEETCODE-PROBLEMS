class Solution {
public:
    static bool compareTimes(const std::string& a, const std::string& b) {
        return a < b;
    }
    int findMinDifference(vector<string>& tp) {
        sort(tp.begin(), tp.end(), compareTimes);
        int mini = INT_MAX;
        for (int i = 0; i < tp.size()-1; i++) {
            string hrs1 = (tp[i].substr(0, 2));
            string mins1 = (tp[i].substr(3));
            string hrs2 = (tp[i + 1].substr(0, 2));
            string mins2 = (tp[i + 1].substr(3));
            int hrsdiff = stoi(hrs2) - stoi(hrs1);
            int minsdiff = stoi(mins2) - stoi(mins1);
            int diff = (hrsdiff * 60) + minsdiff;
            mini = min(mini, diff);
        }
        for(auto it:tp){
            cout<<it<<endl;
        }
        int n=tp.size();
        int hrs1=stoi(tp[0].substr(0,2));
        int mins1=stoi(tp[0].substr(3));
        int hrs2=stoi(tp[n-1].substr(0,2));
        int mins2=stoi(tp[n-1].substr(3));
        int hrsdiff=abs(hrs1-hrs2);
        int minsdiff=abs(mins1-mins2);
        int diff=(hrsdiff*60)+minsdiff;
        mini=min(mini,24*60-diff);
        return mini;
    }
};