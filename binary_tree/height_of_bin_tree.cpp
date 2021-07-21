#include <iostream>
#include <queue>


struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){}
    TreeNode(char x):val(x), left(NULL), right(NULL){}
    TreeNode(char x, TreeNode* l, TreeNode* r):val(x), left(l), right(r){}
};


int height(TreeNode *node) {

    if (node == NULL)
        // if counting starts from 0, return -1
        // else if counting starts from 1 return 1
        return -1;

    int lhs = height(node->left);
    int rhs = height(node->right);
    return std::max(lhs, rhs) + 1;
}


int main() {

    TreeNode* root = new TreeNode('A');

    root->left = new TreeNode('B');
    root->right = new TreeNode('C');

    root->left->left = new TreeNode('D');


    root->right->left = new TreeNode('F');
    root->right->right = new TreeNode('G');

    root->right->left->right = new TreeNode('J');
    root->right->left->right->right = new TreeNode('K');


    /*
    			A
        /				\
        B				C
    /       		/	    \
    D		 		F   	G

                        \
                        J
                            \
                            K
    */

    int height2 = height(root);

    std::cout << height2 << std::endl;


    return 0;
}
