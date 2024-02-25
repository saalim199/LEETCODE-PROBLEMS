class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=INT_MIN;
        int i=0,j=height.size()-1;
        while(i<j){
            int area=(j-i)*min(height[i],height[j]);
            maxi=max(area,maxi);
            if(height[i]>height[j]){
                j--;
            }else i++;
        }
        return maxi;
    }
};