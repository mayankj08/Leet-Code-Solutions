class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        
        std::vector<int> ret;
        if(root == NULL){
            return ret;
        }
        
       
        queue<std::pair<TreeNode*,int>> q;
        q.push(make_pair(root,1));
        int currLevel = 1;
        int max = INT_MIN;
        
        while(q.size()  != 0){
            auto temp = q.front();
            if(temp.second != currLevel){
                currLevel = temp.second;
                ret.push_back(max);
                max = INT_MIN;
            }
            else{
                if(max < temp.first->val )
                    max = temp.first->val;
                if(temp.first->left != NULL){
                     q.push(make_pair(temp.first->left,currLevel+1));
                }
                if(temp.first->right != NULL){
                     q.push(make_pair(temp.first->right,currLevel+1));
                }
                q.pop();
            }
            
            
        }
        ret.push_back(max);
        
        return ret;
    }
};
