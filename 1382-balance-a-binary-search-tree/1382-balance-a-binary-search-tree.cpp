/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> store;
    void inOrder(TreeNode* root){
        if(root == NULL)
            return;
        
        inOrder(root->left);
        store.push_back(root);
        inOrder(root->right);
        
    }
    
    TreeNode* ArraytoTree( int i , int l , int r) {
        if(l > r){
            return NULL;
        }
        
        if(i == l && i == r) {
            store[i]->left = NULL;
            store[i]->right = NULL;
        }
        
        if(i > 0) {
            store[i]->left = ArraytoTree((i-1+l)/2 , l,i-1);
        }
        
        if(i < store.size()-1) {
            store[i]->right = ArraytoTree((i+1+r)/2,i+1,r);
        }
        
        return store[i];
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        inOrder(root);
        int n = store.size();
        
        for(auto i : store) 
            cout<< i->val << " ";
        
        return ArraytoTree((n-1)/2 ,0 , n-1);
    }
};