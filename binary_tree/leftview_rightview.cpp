#include <iostream>
#include <unordered_map>
#include <map>


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){}
    TreeNode(int x):val(x), left(NULL), right(NULL){}
    TreeNode(int x, TreeNode* l, TreeNode* r):val(x), left(l), right(r){}
};

void left_view_map(TreeNode *node, int level, std::map<int, int>& umap) {
//void left_view_map(TreeNode *node, int level, std::unordered_map<int, int>& umap) {
    if (node == NULL) {
        return;
    }

    if (umap.count(level)==0) {
        umap[level] = node->val;
    }

    left_view_map(node->left, level + 1, umap);
    left_view_map(node->right, level + 1, umap);
}

void right_view_map(TreeNode *node, int level, std::map<int, int>& umap) {
//void right_view_map(TreeNode *node, int level, std::unordered_map<int, int>& umap) {
    if (node == NULL) {
        return;
    }

    if (umap.count(level)==0) {
        umap[level] = node->val;
    }

    right_view_map(node->right, level + 1, umap);
    right_view_map(node->left, level + 1, umap);
}


void left_view(TreeNode *node, int& max_level, int level) {

    if (node == NULL) {
        return;
    }

    if(max_level < level){
        std::cout << node->val << std::endl;
        max_level = level;
    }

    left_view(node->left, max_level, level + 1);
    left_view(node->right, max_level, level + 1);
}

void right_view(TreeNode *node, int& max_level, int level) {

    if (node == NULL) {
        return;
    }

    if(max_level < level){
        std::cout << node->val << std::endl;
        max_level = level;
    }

    right_view(node->right, max_level, level + 1);
    right_view(node->left, max_level, level + 1);
}

int main() {

    TreeNode* root = new TreeNode(5);

    root->left = new TreeNode(1);
    root->right = new TreeNode(7);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right->left = new TreeNode(11);
    root->right->right = new TreeNode(13);
    /*
    			5
        /				\
        1				7
    /		\		/		\
    3		4 		11		13

    */

    int max_level = -1;
    left_view(root, max_level, 0);

    max_level = -1;
    right_view(root, max_level, 0);

    return 0;
}
