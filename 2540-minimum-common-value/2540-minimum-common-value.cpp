class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int p1=0,p2=0;
        while(p1<nums1.size() && p2<nums2.size()){
            if(nums1[p1]==nums2[p2]) return nums1[p1];
            else if(nums1[p1]<nums2[p2]) p1++;
            else p2++; 
        }
        return -1;
    }
};