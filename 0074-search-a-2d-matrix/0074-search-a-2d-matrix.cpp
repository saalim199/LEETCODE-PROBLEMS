class Solution {
public:
    int findRow(vector<vector<int>>& matrix, int target){
        int n=matrix.size();
        int low=0;
        int high=matrix.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][matrix[0].size()-1]) return mid;
            else if(target<matrix[mid][0]) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
    bool find(vector<vector<int>>& matrix, int target){
        int r=findRow(matrix,target);
        if(r==-1) return false;
        int n=matrix.size();
        int low=0,high=matrix[r].size()-1;
        while(low<=high){
            int mid=(low+high)/2;
            cout<<mid<<endl;
            if(target==matrix[r][mid]) return true;
            else if(target<matrix[r][mid]) high=mid-1;
            else low=mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return find(matrix,target);
    }
};