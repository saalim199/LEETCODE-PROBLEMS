class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& word) {
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        set<string> st(word.begin(),word.end());
        st.erase(beginWord);
        if(st.find(endWord)== st.end()) return 0;
        while(!q.empty()){
            string w=q.front().first;
            int c=q.front().second;
            q.pop();
            if(w==endWord) return c;
            for(int i=0;i<w.size();i++){
                char original = w[i];
                for(char j='a';j<='z';j++){
                    w[i]=j;
                    if(st.find(w)!=st.end()){
                        q.push({w,c+1});
                        st.erase(w);
                    }
                }
                w[i]=original;
            }
        }
        return 0;
    }
};