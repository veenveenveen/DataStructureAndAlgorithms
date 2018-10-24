//
//  main.cpp
//  SameTree
//
//  Created by 黄启明 on 2018/10/22.
//  Copyright © 2018 Himin. All rights reserved.
//
/*
 Given two binary trees, write a function to check if they are the same or not.
 
 Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
 
 Example 1:
 
 Input:     1         1
           / \       / \
          2   3     2   3
 
         [1,2,3],   [1,2,3]
 
 Output: true
 Example 2:
 
 Input:     1         1
           /           \
          2             2
 
         [1,2],     [1,null,2]
 
 Output: false
 Example 3:
 
 Input:     1         1
           / \       / \
          2   1     1   2
 
         [1,2,1],   [1,1,2]
 
 Output: false
 */
#include <iostream>

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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL ) {
            return true;
        }
        if (p == NULL || q == NULL) {
            return false;
        }
        
        if (p->val != q->val) {
            return false;
        }
        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(int argc, const char * argv[]) {

    TreeNode *tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);
    
    TreeNode *tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(4);
    
    std::cout << Solution().isSameTree(tree1, tree2) << endl;
    
    return 0;
}
