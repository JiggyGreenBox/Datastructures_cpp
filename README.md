# Datastructures_cpp
Quick guide for C++ DS

## Binary tree

* [Binary tree traversals](#binary-tree-traversals)
* [Left Right view tree](#left-right-view-tree)
* [Top Bot view tree](#top-bot-view-tree)
* [Level-Order Traversal](#level-order-traversal)



### Binary tree traversals
```cpp
void inOrderTraversal(TreeNode *node) {
    if(node == NULL) {
        return;
    }
    inOrderTraversal(node->left);
    std::cout << node->val << std::endl;
    inOrderTraversal(node->right);
}

void preOrderTraversal(TreeNode *node) {
    if(node == NULL) {
        return;
    }
    std::cout << node->val << std::endl;
    preOrderTraversal(node->left);
    preOrderTraversal(node->right);
}

void postOrderTraversal(TreeNode *node) {
    if(node == NULL) {
        return;
    }
    postOrderTraversal(node->left);
    postOrderTraversal(node->right);
    std::cout << node->val << std::endl;
}
```

### Left Right view tree
```cpp
int max_level = -1;
void left_view(TreeNode *node, int& max_level, int level) {
    if (node == NULL) 
        return;
        
    // every level print once
    if (max_level < level)
        std::cout << node->val << std::endl;
        max_level = level;
    
    left_view(node->left, max_level, level + 1);
    left_view(node->right, max_level, level + 1);
    
    //right_view(node->right, max_level, level + 1);
    //right_view(node->left, max_level, level + 1);
}
```

### Top Bot view tree
```cpp
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
```

### Level-Order Traversal
```cpp
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
```


