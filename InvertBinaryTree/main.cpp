//
//  main.cpp
//  InvertBinaryTree
//
//  Created by 黄启明 on 2018/10/22.
//  Copyright © 2018 Himin. All rights reserved.
//

/*
 Invert a binary tree.
 
 Example:
 
 Input:
 
      4
    /   \
   2     7
  / \   / \
 1   3 6   9
 Output:
 
      4
    /   \
   7     2
  / \   / \
 9   6 3   1
 Trivia:
 This problem was inspired by this original tweet by Max Howell:
 
 Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.
 */

#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),left(NULL),right(NULL){}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return NULL;
        }
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
