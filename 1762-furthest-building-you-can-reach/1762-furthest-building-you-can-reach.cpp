class Solution {
public:    
    int furthestBuilding(vector<int>& h, int b, int l) {
        priority_queue<int> p;
        int i=0;
        for(i=0;i<h.size()-1;i++){
            if(h[i+1]<=h[i]) continue;
            else{
                int diff=h[i+1]-h[i];
                b-=diff;
                p.push(diff);
                if(b<0){
                    b+=p.top();
                    p.pop();
                    l--;
                }
                if(l<0) return i;
            }
        }
        return i;
    }
};