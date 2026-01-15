class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int,int> mp;
        for(auto &num : nums2){
            while(!st.empty() && st.top()<num){
                int ele=st.top();
                st.pop();
                mp[ele]=num;
            }
            st.push(num);
        }
        vector<int> ans;
        for(auto &num : nums1){
            if(mp[num]){
                ans.push_back(mp[num]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};