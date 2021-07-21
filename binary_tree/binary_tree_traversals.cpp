#include <iostream>



struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){}

    TreeNode(int x):val(x), left(NULL), right(NULL){}

    TreeNode(int x, TreeNode* l, TreeNode* r):val(x), left(l), right(r){}
};

void inOrderTraversal(TreeNode *node){
    if(node == NULL){
        return;
    }
    inOrderTraversal(node->left);
    std::cout << node->val << std::endl;
    inOrderTraversal(node->right);
}

void preOrderTraversal(TreeNode *node){
    if(node == NULL){
        return;
    }
    std::cout << node->val << std::endl;
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

void postOrderTraversal(TreeNode *node){
    if(node == NULL){
        return;
    }
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    std::cout << node->val << std::endl;
}

int main() {

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(1);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->right = new TreeNode(13);

    inOrderTraversal(root);

    std::cout << "\n"<< std::endl;

    preOrderTraversal(root);

    std::cout << "\n"<< std::endl;

    postOrderTraversal(root);

    return 0;
}
