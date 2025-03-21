class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> mp;
        stack<int> st;
        for(int i=0;i<nums2.size();i++){
            int num=nums2[i];
            if(!st.empty() && st.top()<num){
                while(!st.empty() && st.top()<num){
                    mp[st.top()]=num;
                    st.pop();
                }
            }
            st.push(num);
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            if(mp[nums1[i]]){
                ans.push_back(mp[nums1[i]]);
            }else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};