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
    vector<TreeNode*> solve(int st , int end) {
        if(st > end){
            return {NULL};    
        }
        
        if(st == end) {
            TreeNode* root = new TreeNode(st);
            return {root};
        }
        
        vector<TreeNode*> res;
        for(int i=st; i<=end; i++) {
            vector<TreeNode*> left = solve(st,i-1);
            vector<TreeNode*> right = solve(i+1,end);
            
            for(TreeNode* l : left) {
                for(TreeNode* r : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
      
        return solve(1,n);
       
    }
};