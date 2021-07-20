#include <iostream>
#include <unordered_map>
#include <map>


struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){}
    TreeNode(char x):val(x), left(NULL), right(NULL){}
    TreeNode(char x, TreeNode* l, TreeNode* r):val(x), left(l), right(r){}
};


void top_view(TreeNode *node, int level, int bias, std::map<int, std::pair<char,int>> &umap) {

    if (node == NULL)
        return;

    // lower level means the node is higher
    // replace with lower level
    if (umap.count(bias) == 0 || umap[bias].second > level)
        umap[bias] = std::make_pair(node->val, level);

    top_view(node->left, level+1, bias-1, umap);
    top_view(node->right, level+1, bias+1, umap);
}

void bot_view(TreeNode *node, int level, int bias, std::map<int, std::pair<char,int>> &umap) {

    if (node == NULL)
        return;

    // higher level means the node is lower
    // replace with higher level
    if (umap.count(bias) == 0 || umap[bias].second < level)
        umap[bias] = std::make_pair(node->val, level);

    bot_view(node->left, level+1, bias-1, umap);
    bot_view(node->right, level+1, bias+1, umap);
}


int main() {

    TreeNode* root = new TreeNode('A');

    root->left = new TreeNode('B');
    root->right = new TreeNode('C');

    root->left->left = new TreeNode('D');
    root->left->right = new TreeNode('E');


    root->right->right = new TreeNode('G');
    /*
    			A
        /				\
        B				C
    /		\				\
    D		E 				G


    bias
    -2  -1      0       1      2
    */


    //       bias,          char, level
    std::map<int, std::pair<char, int>> umap;
    int bias = 0;
    int level = 0;
    top_view(root, level, bias, umap);

    for(auto x: umap) {
        //std::cout << x.second.second << std::endl;
        std::cout << x.first << x.second.first << x.second.second << std::endl;
    }

    std::cout << std::endl;
    umap.clear();
    bias = 0;
    level = 0;
    bot_view(root, level, bias, umap);

    for(auto x: umap) {
        //std::cout << x.second.second << std::endl;
        std::cout << x.first << x.second.first << x.second.second << std::endl;
    }

    return 0;
}
