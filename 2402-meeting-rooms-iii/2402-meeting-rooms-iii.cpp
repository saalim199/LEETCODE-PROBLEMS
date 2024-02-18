#define ll long long
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& m) {
        set<ll> s;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,
                       greater<pair<ll, ll>>>
            me;
        sort(m.begin(), m.end());
        vector<int> count(n, 0);
        for (int i = 0; i < n; i++) {
            s.insert(i);
        }
        for(int i=0;i<m.size();i++){
            ll start=m[i][0];
            ll end=m[i][1];
            while(!me.empty() && me.top().first<=start){
                s.insert(me.top().second);
                me.pop();
            }
            if(s.size()==0){
                pair<ll,ll> p=me.top();
                me.pop();
                ll d=end-start;
                start=p.first;
                end=start+d;
                s.insert(p.second);
            }
            auto it=s.begin();
            count[*it]++;
            me.push({end,*it});
            s.erase(*it);
        }
        int maxi=INT_MIN;
        int res=-1;
        for(int i=0;i<n;i++){
            cout<<count[i]<<endl;
            if(maxi<count[i]){
                res=i;
                maxi=count[i];
            }
        }
        return res;
    }
};