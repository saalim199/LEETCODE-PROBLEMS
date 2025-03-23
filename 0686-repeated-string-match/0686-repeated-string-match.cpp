class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int maxi=100000/a.size();
        int low=1,high=maxi;
        while(low<high){
            int mid=(low+high)/2;
            string temp="";
            for(int i=0;i<mid;i++) temp+=a;
            // cout<<temp<<endl;
            if(temp.find(b)>=temp.size()){
                low=mid+1;
            }else{
                high=mid;
            }
        }
        if(low>=maxi) return -1;
        return low;
    }
};