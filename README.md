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

Left/Right view tree:
```cpp
int max_level = -1;
void left_view(TreeNode *node, int& max_level, int level) {
    if (node == NULL) {
        return;
    }
    if (max_level < level) {
        std::cout << node->val << std::endl;
        max_level = level;
    }
    left_view(node->left, max_level, level + 1);
    left_view(node->right, max_level, level + 1);
    
    //right_view(node->right, max_level, level + 1);
    //right_view(node->left, max_level, level + 1);
}
```


