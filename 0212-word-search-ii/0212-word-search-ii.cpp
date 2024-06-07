class Solution {
public:
    vector<string> ans;
    int m , n;
    
    struct treiNode {
        bool end;
        string word;
        treiNode* child[26];
    };
    
    treiNode* getNode() {
        treiNode* newNode = new treiNode();
        newNode->end = false;
        
        newNode->word = "";
        
        for(int i=0; i<26; i++) {
            newNode->child[i] = NULL;
        }
        return newNode;
    }
    
    void insert(treiNode* root,string &s) {
        treiNode* noyc = root;
        
        for(int i=0; i<s.length(); i++){
            char ch = s[i];
            if(root->child[ch-'a'] == NULL) {
                root->child[ch-'a'] = getNode();
            } 
            root = root->child[ch-'a'];
        }
        
        root->end = true;
        root->word = s;
    }
    
    vector<vector<int>> direc{{1,0},{-1,0},{0,1},{0,-1}};
   
    void findWord(vector<vector<char>> &board , int i, int j, treiNode* root) {
        if(i<0 || i>=m || j<0 || j>=n)
               return ;
        
        if(board[i][j] == '$' || root->child[board[i][j]-'a'] == NULL)
              return ;
        
        root = root->child[board[i][j]-'a'];
        if(root->end == true) {
            ans.push_back(root->word);
            root->end = false;
        }
        
        char temp = board[i][j];
        board[i][j] = '$';
        
        //left , right , top , down
        
        for(vector<int> &dir : direc) {
            int newi = i + dir[0];
            int newj = j + dir[1];
            
            findWord(board,newi,newj,root);
        }
        board[i][j] = temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        
        
        treiNode* root = getNode();
        
        for(string &s : words) {
            insert(root,s);
        }
        
        //traverse grid only once
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                char ch = board[i][j];
                
                if(root->child[ch-'a'] != NULL) {
                    findWord(board,i,j,root);
                }
            }
        }
        return ans;
    }
};