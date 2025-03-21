class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> st;
        int n=heights.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int start=i;
            while(!st.empty() && st.top().first>=heights[i]){
                auto [h,idx] = st.top();
                st.pop();
                ans=max(ans,h*(i-idx));
                start=idx;
            }
            st.push({heights[i],start});
        }
        while(!st.empty()){
            auto [h,idx] = st.top();
            st.pop();
            ans=max(ans,h*(n-idx));
        }
        return ans;
    }
};