class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=INT_MAX;
        int res=0;
        for(int i=0;i<prices.size();i++){
            if((prices[i]-mini)>res) res=(prices[i]-mini);
            if(mini>prices[i]) mini=prices[i];
        }
        return res;
    }
};