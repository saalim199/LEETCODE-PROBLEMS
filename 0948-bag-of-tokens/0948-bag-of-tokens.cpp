class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int i=0,j=tokens.size()-1;
        int score=0;
        while(i<=j){
            if(i==j){
                if(power<tokens[i]){
                    return score;
                }else{
                    return score+1;
                }
            }
            if(power<tokens[i] && score>=1){
                power+=tokens[j--];
                score--;
            }else if(power<tokens[i] && score<1){
                return score;
            }else{
                power-=tokens[i++];
                score++;
            }
        }
        return score;
    }
};