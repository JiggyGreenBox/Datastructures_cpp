# Datastructures_cpp
Quick guide for C++ DS

### Binary tree
Binary tree traversals:
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

