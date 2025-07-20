class Trie {
public:
    unordered_map<char,Trie*> children;
    bool flag=false;
    Trie() {
        
    }
    
    void insert(string word) {
        Trie* node=this;
        for(auto &w : word){
            if(!node->children.count(w)){
                node->children[w]=new Trie();
            }
            node=node->children[w];
        }
        node->flag=true;
    }
    
    bool search(string word) {
        Trie* node=this;
        for(auto w:word){
            if(!node->children.count(w)){
                return false;
            }
            node=node->children[w];
        }
        if(node->flag) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for(auto w :  prefix){
            if(!node->children.count(w)){
                return false;
            }
            node=node->children[w];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */