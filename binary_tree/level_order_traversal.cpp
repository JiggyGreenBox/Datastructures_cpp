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


void level_order_traversal(TreeNode *root) {

    if (root == NULL)
        return;

    std::queue<TreeNode*> q;

    q.push(root);

    TreeNode *curr;

    while(!q.empty()) {
        curr = q.front();
        std::cout << curr->val << std::endl;
        q.pop();

        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}


int main() {

    TreeNode* root = new TreeNode('A');

    root->left = new TreeNode('B');
    root->right = new TreeNode('C');

    root->left->left = new TreeNode('D');
    root->left->right = new TreeNode('E');

    root->right->left = new TreeNode('F');
    root->right->right = new TreeNode('G');
    /*
    			A
        /				\
        B				C
    /		\		/	    \
    D		E 		F   	G
    */

    level_order_traversal(root);


    return 0;
}
