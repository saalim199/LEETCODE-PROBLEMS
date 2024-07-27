class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>> graph(26,vector<int>(26,INT_MAX));
        for(int i=0;i<26;i++){
            graph[i][i]=0;
        }
        for(int i=0;i<original.size();i++){
            int x=original[i]-'a';
            int y=changed[i]-'a';
            graph[x][y]=min(graph[x][y],cost[i]);
        }
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                for(int k=0;k<26;k++){
                    if((graph[j][i]<INT_MAX) && (graph[i][k]<INT_MAX)) graph[j][k]=min(graph[j][k],graph[j][i]+graph[i][k]);
                }
            }
        }
        long long int res=0;
        for(int i=0;i<source.size();i++){
            if(graph[source[i]-'a'][target[i]-'a']>=INT_MAX){
                return -1;
            }
            res+=graph[source[i]-'a'][target[i]-'a'];
        }
        return res;
    }
};