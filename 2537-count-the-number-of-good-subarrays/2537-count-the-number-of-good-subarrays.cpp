class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        long long ans=0;
        long long goodPairs=0;
        int left=0;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            goodPairs+=freq[nums[i]]-1;
            cout<<goodPairs<<" ";
            if(goodPairs>=k){
                while(left<=i && goodPairs>=k){
                    ans+=nums.size()-i;
                    freq[nums[left]]--;
                    goodPairs-=freq[nums[left]];
                    left++;
                }
            }
        }
        // cout<<endl;
        // for(int i=0;i<nums.size();i++){
        //     freq[nums[i]]--;
        //     goodPairs-=freq[nums[i]];
        //     cout<<goodPairs<<" ";
        //     if(goodPairs>=k) ans++;
        //     else break;
        // }
        return ans;
    }
};