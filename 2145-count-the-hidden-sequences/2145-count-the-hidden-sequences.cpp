class Solution {
public:
    int numberOfArrays(vector<int>& diff, int lower, int upper) {
        long long sum=0, maxi=0, mini=0;
        for(int i=0;i<diff.size();i++){
            sum+=diff[i];
            maxi=max(maxi,sum);
            mini=min(mini,sum);
        }
        return max(0LL,(upper-maxi)-(lower-mini)+1);
    }
};