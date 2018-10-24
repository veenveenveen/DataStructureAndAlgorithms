//
//  main.cpp
//  SearchinaBinarySearchTree
//
//  Created by 黄启明 on 2018/10/22.
//  Copyright © 2018 Himin. All rights reserved.
//
/*
 Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's value equals the given value. Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.
 
 For example,
 
 Given the tree:
     4
    / \
   2   7
  / \
 1   3
 
 And the value to search: 2
 You should return this subtree:
 
   2
  / \
 1   3
 In the example above, if we want to search the value 5, since there is no node with value 5, we should return NULL.
 
 Note that an empty tree is represented by NULL, therefore you would see the expected output (serialized tree format) as [], not null.
 */
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    TreeNode *node = NULL;
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        order(root, val);
        return node;
    }
    
    void order(TreeNode* root, int val) {
        if (root->val == val) {
            node = root;
            return;
        }
        if (val < root->val && root->left) {
            order(root->left, val);
        }
        if (val > root->val && root->right) {
            order(root->right, val);
        }
    }
};

//TreeNode* searchBST(TreeNode* root, int val) {
//    if (!root) { return NULL; }
//    if (val < root->val) {
//        return searchBST(root->left,val);
//    } else if (val > root->val) {
//        return searchBST(root->right,val);
//    } else {
//        return root;
//    }
//}

void printTree(TreeNode *tree) {
    if (!tree) {
        return;
    }
    cout << to_string(tree->val)+"->";
    if (tree->left) {
        printTree(tree->left);
    }
    if (tree->right) {
        printTree(tree->right);
    }
}

int main(int argc, const char * argv[]) {
    TreeNode *tree = new TreeNode(4);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(7);
    tree->left->left = new TreeNode(1);
    tree->left->right = new TreeNode(3);
    
    printTree(tree);

    std::cout << "Hello, World!\n";
    TreeNode *node = Solution().searchBST(tree, 7);
    printTree(node);
    return 0;
}
