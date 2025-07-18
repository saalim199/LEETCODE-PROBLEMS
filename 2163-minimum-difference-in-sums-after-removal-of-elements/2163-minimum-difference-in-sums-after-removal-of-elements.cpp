class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n=nums.size()/3;
        priority_queue<long long> leftHeap;
        priority_queue<long long, vector<long long>, greater<long long>> rightHeap;
        vector<long long> minLeft;
        vector<long long> minRight;
        long long currSum=0;
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            leftHeap.push(nums[i]);
        }
        minLeft.push_back(currSum);
        for(int i=n;i<2*n;i++){
            leftHeap.push(nums[i]);
            currSum+=nums[i];
            currSum-=leftHeap.top();
            leftHeap.pop();
            minLeft.push_back(currSum);
        }
        currSum=0;
        for(int i=nums.size()-1;i>=2*n;i--){
            currSum+=nums[i];
            rightHeap.push(nums[i]);
        }
        minRight.push_back(currSum);
        for(int i=(2*n-1);i>=n;i--){
            rightHeap.push(nums[i]);
            currSum+=nums[i];
            currSum-=rightHeap.top();
            rightHeap.pop();
            minRight.push_back(currSum);
        }
        int k=minRight.size();
        long long res=LLONG_MAX;
        for(int i=0;i<k;i++){
            res=min(res,minLeft[i]-minRight[k-i-1]);
        }
        return res;
    }
};