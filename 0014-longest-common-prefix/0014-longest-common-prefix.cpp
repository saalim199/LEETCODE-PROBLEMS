struct Trie{
    Trie* children[26];
    int count=0;
    void insert(string &str){
        Trie* node=this;
        for(auto &ch:str){
            if(!node->children[ch-'a']){
                node->children[ch-'a']=new Trie();
            }
            node=node->children[ch-'a'];
            node->count++;
        }
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        Trie* root=new Trie();
        int n=strs.size();
        for(auto &s: strs){
            root->insert(s);
        }
        for(auto &s : strs[0]){
            root=root->children[s-'a'];
            if(root->count==n) ans+=s;
            else break;
        }
        return ans;
    }
};