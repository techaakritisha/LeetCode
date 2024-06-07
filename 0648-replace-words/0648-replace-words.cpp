class Solution {
public:
    struct trieNode {
        trieNode *children[26];
        bool isEnd;
    };
    
    trieNode* getNode() {
        trieNode* newnode = new trieNode();
        newnode->isEnd = false;
        
        for(int i=0; i<26; i++) {
            newnode->children[i] = NULL;
        }
        
        return newnode;
    }
    trieNode* root;
    
    void insert(string word) {
        trieNode* crawier = root;
        
        for(int i=0; i<word.length(); i++) {
            int idx = word[i] - 'a';
            
            if(crawier->children[idx] == NULL) {
                crawier->children[idx] = getNode();
            }
            crawier = crawier->children[idx];
        }
        crawier->isEnd = true;
    }
    
    string search(string word) {
        trieNode* crawier = root;
        for(int i=0; i<word.length(); i++) {
            int idx = word[i] - 'a';
            if(crawier->children[idx] == NULL){
                return word;
            }
            crawier = crawier->children[idx];
            if(crawier->isEnd) {
                return word.substr(0,i+1);
            }
        }
        return word;
    }
    string replaceWords(vector<string>& dictionary, string sent) {
       root = getNode();
    
        for(string &s : dictionary) {
            insert(s);
        }
        
        stringstream ss(sent);
        
        string word;
        string result;
        
        while(getline(ss,word,' ')) {
            result += search(word) + " ";
            
        }
        result.pop_back();
        
        return result;
    }
};