class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int totalCount=0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                for(int k=j+1;k<arr.size();k++){
                    int diffA=abs(arr[i]-arr[j]);
                    int diffB=abs(arr[j]-arr[k]);
                    int diffC=abs(arr[i]-arr[k]);
                    if(diffA<=a && diffB<=b && diffC<=c) totalCount++;
                }
            }
        }
        return totalCount;
    }
};