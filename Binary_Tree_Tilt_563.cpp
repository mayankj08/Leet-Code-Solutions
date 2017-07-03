/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    int findSum(TreeNode* root){
        if(root == NULL)
            return 0;
        
        int sum = 0;
        sum += findSum(root->left);
        sum += findSum(root->right);
        sum += root->val;
        
        return sum;
    }
    
    int findTiltInternal(TreeNode* root) {
        
        if(root == NULL)
            return 0;
    
        int val1 = 0;
        
        if(root->left != NULL)
            val1 = findSum(root->left);
        
        int val2 = 0;
        if(root->right != NULL)
            val2 = findSum(root->right);
        
        if(val1>val2)
            return val1-val2;
        else
            return val2-val1;
    }
    
    int findTilt(TreeNode* root){
    
        int ret = 0;
        
        if(root != NULL)
            ret = findTiltInternal(root);
        
        if(root!= NULL and root->left != NULL)
            ret += findTilt(root->left);
        
        if(root!= NULL and root->right != NULL)
        ret += findTilt(root->right);
        
        return ret;
    }
};
