class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        int maxi=0;
        int finalMaxi=0;
        int cnt=0;
        int i=0;
        queue<int> q;
        while(cnt<=k){
            cnt++;
            if(i==0) q.push(startTime[i]);
            else if(i==n) q.push(eventTime-endTime[n-1]);
            else q.push(startTime[i]-endTime[i-1]);
            maxi+=q.back();
            i++;
        }
        finalMaxi=maxi;
        for(int j=i;j<=n;j++){
            maxi-=q.front();
            q.pop();
            if(j==n) q.push(eventTime-endTime[n-1]);
            else q.push(startTime[j]-endTime[j-1]);
            maxi+=q.back();
            finalMaxi=max(maxi,finalMaxi);
        }
        return finalMaxi;
    }
};