class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // if(trust.size()==0 && n==1) return 1;
        // vector<int> v(n+1,0);
        // set<int> s;
        // for(int i=0;i<trust.size();i++){
        //     v[trust[i][0]]++;
        //     if(v[trust[i][0]]==1)
        //         s.insert(trust[i][1]);
        // }
        // int c=0;
        // for(int i=1;i<=n;i++){
        //     if(v[i]==0) c++;
        // }
        // cout<<c<<endl;
        // if(s.size()==1 && c==1){
        //     auto itr=s.begin();
        // for(int i=1;i<=n;i++){
        //     if(v[i]<=0 && *itr==i) return i;
        // }
        // }
        // return -1;
        vector<vector<int>> v(n+1,vector<int>(n+1,0));
        for(int i=0;i<trust.size();i++){
            v[trust[i][0]][trust[i][1]]++;
        }
        for(int i=1;i<=n;i++){
            int cnt=0;
            for(int j=1;j<=n;j++){
                if(i==j && v[i][j]!=0) break; 
                if(v[j][i]>0) cnt++;
            }
            if(cnt==(n-1)){
                cout<<i<<endl;
                int f=1;
                for(int k=1;k<=n;k++){
                    if(v[i][k]!=0){
                        f=0;
                        break;
                    } 
                }
                if(f) return i;
            }
        }
        return -1;
    }
};