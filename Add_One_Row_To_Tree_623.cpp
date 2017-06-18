// C program to demonstrate insert operation in binary search tree
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
#include<queue>
//#include<pair>

struct node
{
	int key;
	struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d \n", root->key);
		inorder(root->right);
	}
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key); 

	/* return the (unchanged) node pointer */
	return node;
}

node* addOneRow(node* root, int v, int d) {

    if(d==1){
        auto newNd = new node;

        newNd->key = v;
        newNd->left = root;
        return newNd;

    }

    std::queue<std::pair<node*,int>> nodes;

    nodes.push(std::make_pair(root,1));
    while(1){
        // pop first element from map    
        auto currNode = nodes.front();

        //std::cout << "CurrNode depth:" << currNode.second << " " << d-1 << '\n';
        
        if(currNode.second == d-1){
            break;
        }

        if(currNode.first->left != NULL){
            nodes.push(std::make_pair(currNode.first->left,currNode.second+1));
        }

        if(currNode.first->right != NULL){
            nodes.push(std::make_pair(currNode.first->right,currNode.second+1));
        }

        nodes.pop();

       //std::cout << "Insiude " << '\n';

    }

    //std::cout << nodes.size();
    
    while(!nodes.empty()){
        auto currNode = nodes.front().first;

        auto leftChild = currNode->left;
        auto rightChild = currNode->right;

        // Allocate memory to two new nodes
        auto newLeft = new node;
        auto newRight = new node;

        newLeft->key = v;
        newRight->key = v;

        currNode->left = newLeft;
        currNode->right = newRight;

        newRight->left = NULL;
        newRight->right = NULL;
        newRight->right = rightChild;
        newLeft->left = leftChild;
        
        nodes.pop();
    }
}

// Driver Program to test above functions
int main()
{
	/* Let us create following BST
			50
		/	 \
		30	 70
		/ \ / \
	20 40 60 80 */
	struct node *root = NULL;
	root = insert(root, 50);
	/*insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);*/

    inorder(root);
    std::cout << "Adding " <<std::endl;
    auto newNd =addOneRow(root,10,1);
    inorder(newNd);

	// print inoder traversal of the BST

	return 0;
}

