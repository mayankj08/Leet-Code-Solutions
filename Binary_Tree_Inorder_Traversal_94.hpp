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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> out;
        
        if(root == NULL){
            return out;
        }
        
        if(root->left != NULL){
            vector<int> curr;
            if(out.size() == 0){
                out = inorderTraversal(root->left);
            }
            else{
                curr = inorderTraversal(root->left);
                out.insert(out.end(), curr.begin(), curr.end());
            }
        }
        out.push_back(root->val);
        if(root->right != NULL){
            vector<int> curr;
            if(out.size() == 0){
                out = inorderTraversal(root->right);
            }
            else{
                curr = inorderTraversal(root->right);
                out.insert(out.end(), curr.begin(), curr.end());
            }
        }
        return out;
    }
};
