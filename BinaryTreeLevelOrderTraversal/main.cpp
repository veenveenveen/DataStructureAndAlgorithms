//
//  main.cpp
//  BinaryTreeLevelOrderTraversal
//
//  Created by 黄启明 on 2018/10/22.
//  Copyright © 2018 Himin. All rights reserved.
//
/*
 Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 
 For example:
 Given binary tree [3,9,20,null,null,15,7],
        3
       / \
      9  20
        /  \
       15   7
 return its bottom-up level order traversal as:
 [
    [15,7],
    [9,20],
    [3]
 ]
 */
#include <iostream>
#include <vector>
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
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        levelOrder(root, res, 0);
        reverse(res.begin(), res.end());
        return res;
    }
    
private:
    void levelOrder(TreeNode* root, vector<vector<int>> &res, int level) {
        if (!root) { return; }
        if (level == res.size()) { res.push_back({}); }
        res[level].push_back(root->val);
        levelOrder(root->left, res, level+1);
        levelOrder(root->right, res, level+1);
    }
};

int main(int argc, const char * argv[]) {

    
    std::cout << "Hello, World!\n";
    return 0;
}
