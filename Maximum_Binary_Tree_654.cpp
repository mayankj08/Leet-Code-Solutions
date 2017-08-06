#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void printInorder(struct TreeNode* TreeNode)
{
     if (TreeNode == NULL)
          return;
 
     /* first recur on left child */
     printInorder(TreeNode->left);
 
     /* then print the data of TreeNode */
     printf("%d ", TreeNode->val);  
 
     /* now recur on right child */
     printInorder(TreeNode->right);
}


TreeNode* constructMaximumBinaryTree(vector<int> nums) {

    auto iter = std::max_element(nums.begin(),nums.end());
    int idx = std::distance(nums.begin(),iter);


    for(auto elem:nums){
        std::cout << elem << " ";
    }
    std::cout << "\n";

    TreeNode* root = new TreeNode(nums[idx]);

    
    if(idx == nums.size()-1){
        //No right subtree
    }
    else{
        std::vector<int> rightSubtree(nums.begin()+idx+1,nums.end());
        auto rightNode = constructMaximumBinaryTree(rightSubtree);
        root->right = rightNode;
    }

    if(idx==0){
    }
    else{
        std::vector<int> leftSubtree(nums.begin(),nums.begin()+idx);
        auto leftNode = constructMaximumBinaryTree(leftSubtree);
        root->left = leftNode;
    }

    return root;
}

int main(){

    std::vector<int> elem = {3,2,1,6,0,5} ;
    auto root = constructMaximumBinaryTree(elem);
    printInorder(root);
    

    return 0;
}
