class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        // for(int i=0;i<nums.size();i++){
        //     nums[i]*=nums[i];
        // }
        // sort(nums.begin(),nums.end());
        // return nums;
        int i=nums.size();
        int j=-1;
        for(int k=0;k<nums.size();k++){
            if(nums[k]>=0){ i=k; break;}
        }
        j=i-1;
        vector<int> ans;
        while(j>=0 && i<nums.size()){
            int sq1=nums[j]*nums[j];
            int sq2=nums[i]*nums[i];
            if(sq1<sq2){
                ans.push_back(sq1);
                j--;
            }else{
                ans.push_back(sq2);
                i++;
            }
        }
        while(j>=0){
            ans.push_back(nums[j]*nums[j]);
            j--;
        }
        while(i<nums.size()){
            ans.push_back(nums[i]*nums[i]);
            i++;
        }
        return ans;
    }
};