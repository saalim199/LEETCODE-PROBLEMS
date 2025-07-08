class Event{
    public:
        int startDay;
        int endDay;
        int value;
};
class Solution {
public:
    static bool comp(Event e1, Event e2){
        return e1.startDay<e2.startDay;
    }

    int findNextEvent(vector<Event> &events, int idx) {
        int endTime = events[idx].endDay;  
        int left = idx + 1;
        int right = events.size() - 1;
        int result = -1;
        
  
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (events[mid].startDay > endTime) {
                result = mid;     
                right = mid - 1;  
            } else {
                left = mid + 1;   
            }
        }
        
        return result;
    }

    int helper(int i, vector<Event> &events, int k, vector<vector<int>> &dp){
        if(i>=events.size() || k==0){
            return 0;
        }
        if(dp[i][k] != -1) return dp[i][k];
        int notTaken = helper(i+1,events,k,dp);
        int taken = events[i].value;
        int nextI=findNextEvent(events,i);
        if(nextI!=-1) taken+=helper(nextI,events,k-1,dp);
        return dp[i][k]=max(taken,notTaken);
    }

    int maxValue(vector<vector<int>>& events, int k) {
        vector<Event> v;
        for(auto e:events){
            Event t=Event();
            t.startDay=e[0];
            t.endDay=e[1];
            t.value=e[2];
            v.push_back(t);
        }
        sort(v.begin(),v.end(),comp);
        vector<vector<int>> dp(events.size()+1,vector<int>(k+1,-1));
        return helper(0,v,k,dp);
    }
};