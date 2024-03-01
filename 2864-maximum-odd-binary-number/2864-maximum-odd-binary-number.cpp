class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int count=0;
        for(auto w:s){
            if(w=='1') count++;
        }
        string w="";
        if(count==1) {w.insert(0,s.size()-1,'0'); w.push_back('1'); return w;}
        for(int i=0;i<s.size()-1;i++){
            if(count!=1) {w.push_back('1'); count--;}
            else{
                w.push_back('0');
            }
        }
        w.push_back('1');
        return w;
    }
};