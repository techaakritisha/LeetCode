class Trie {
public:
    
    struct trieNode{
        bool end;
        trieNode* child[26];
    };
    
    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        
        newNode->end = false;
        
        for(int i=0; i<26; i++){
            newNode->child[i] = NULL;
        }
        return newNode;
    }
    
    trieNode * root;
    
    Trie() {
       root = getNode();   
    }
    
    void insert(string word) {
        trieNode* copy = root;
        
        for(int i=0; i<word.length(); i++) {
            char ch = word[i];
            
            if(copy->child[ch-'a'] == NULL){
                copy->child[ch-'a'] = getNode();
            }
            
            copy = copy->child[ch-'a'];
        }
        copy->end = true;
    }
    
    bool search(string word) {
      trieNode* copy = root;
        
        for(int i=0; i<word.length(); i++){
            int ch = word[i]-'a';
            if(!copy->child[ch])
                return false;
            
            copy = copy->child[ch];
        }
        
        if(copy != NULL && copy->end == true)
             return true;
        
        return false;
    }
    
    bool startsWith(string prefix) {
        trieNode* copy = root;
        
        int i = 0;
        
        for(i=0; i<prefix.length(); i++){
            int ch = prefix[i]-'a';
            
            if(copy->child[ch] == NULL)
                return false;
            
            copy = copy->child[ch];
        }
        
        if(i == prefix.length())
             return true;
        
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */