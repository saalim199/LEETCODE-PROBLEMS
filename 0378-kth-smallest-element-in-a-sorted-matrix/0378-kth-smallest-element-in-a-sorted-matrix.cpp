class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l=INT_MAX,h=INT_MIN;
        for(int i=0;i<matrix.size();i++){
            l=min(l,matrix[i][0]);
            h=max(h,matrix[i][matrix.size()-1]);
        }
        while(l<=h){
            int m=(l+h)/2;
            int c=0;
            for(int i=0;i<matrix.size();i++)
                c+=upper_bound(matrix[i].begin(),matrix[i].end(),m)-matrix[i].begin();
            if(c<=(k-1)) l=m+1;
            else h=m-1;
        }
        return l;
    }
};