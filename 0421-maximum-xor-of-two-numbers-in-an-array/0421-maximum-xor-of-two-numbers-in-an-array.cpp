class Solution {
public:
    struct trieNode{
        trieNode* left;
        trieNode* right;
    };
    
    void insert(trieNode* root , int &num) {
        trieNode* copy = root;
        
        for(int i=31; i>=0; i--){
            
            int ith = (num >> i) & 1;
            
            if(ith == 0){
                if(copy->left == NULL) {
                    copy->left = new trieNode();
                }
                copy = copy->left;
            }
            else{
                 if(copy->right == NULL) {
                    copy->right = new trieNode();
                }
                copy = copy->right;
            }
        }
    }
    
    int findmaxXOR(trieNode* root , int &num) {
        int maxi = 0;
        trieNode* copy = root;
        
        for(int i=31; i>=0; i--){
            int ith = (num>>i) & 1;
            
            if(ith == 1) {
               if(copy->left != NULL) {
                   maxi += pow(2,i);
                   copy = copy->left;
               }
                else{
                    copy = copy->right;
                }
            }
            else{
               if(copy->right != NULL) {
                   maxi += pow(2,i);
                   copy = copy->right;
               }
                else{
                    copy = copy->left;
                } 
            }
        }
        return maxi;
    }

    int findMaximumXOR(vector<int>& nums) {
        trieNode* root = new trieNode();
        
        for(int &num : nums) {
            insert(root,num);
        }
        
        int ans = 0;
        
        for(int i=0; i<nums.size(); i++){
            int temp = findmaxXOR(root,nums[i]);
            ans = max(ans,temp);
        }
        
        return ans;
    }
};