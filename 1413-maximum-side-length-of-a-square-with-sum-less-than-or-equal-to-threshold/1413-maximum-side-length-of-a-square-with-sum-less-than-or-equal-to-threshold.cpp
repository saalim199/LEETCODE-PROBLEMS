class Solution {
public:
    bool cal(vector<vector<int>> &mat,int i1,int j1,int i2,int j2,int s){
        int sum=0;
        if(((i1-1)<0) && ((j1-1)>=0)) sum=mat[i2][j2]-mat[i2][j1-1];
        else if(((i1-1)<0) && ((j1-1)<0)) sum=mat[i2][j2];
        else if(((i1-1)>=0) && ((j1-1)<0)) sum=mat[i2][j2]-mat[i1-1][j2];
        else sum=mat[i2][j2]-mat[i1-1][j2]-mat[i2][j1-1]+mat[i1-1][j1-1];
        if(sum<=s) return 1;
        else return 0;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int r=mat.size();
        int c=mat[0].size();
        for(int i=1;i<c;i++){
            mat[0][i]+=mat[0][i-1];
        }
        for(int i=1;i<r;i++){
            mat[i][0]=mat[i][0]+mat[i-1][0];
        }
        for(int i=1;i<r;i++)
            {for(int j=1;j<c;j++){
                mat[i][j]+=mat[i-1][j]+mat[i][j-1]-mat[i-1][j-1];
            }
        }
        int l=1,h=min(r,c);
        while(l<=h){
            int m=(l+h)/2;
            bool res=0;
            for(int i=0;i<=r-m;i++){
                for(int j=0;j<=c-m;j++){
                    res=cal(mat,i,j,i+(m-1),j+(m-1),threshold);
                    if(res){
                        break;
                    }
                }
                if(res){
                        break;
                    }
            }
            if(res) l=m+1;
            else h=m-1;
        }
        return l-1;
    }
};
