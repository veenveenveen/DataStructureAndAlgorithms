//
//  main.cpp
//  BinaryTreePaths
//
//  Created by 黄启明 on 2018/10/22.
//  Copyright © 2018 Himin. All rights reserved.
//
/*
 Given a binary tree, return all root-to-leaf paths.
 
 Note: A leaf is a node with no children.
 
 Example:
 
 Input:
 
    1
   / \
  2   3
   \
    5
 
 Output: ["1->2->5", "1->3"]
 
 Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
private:
    vector<string> res;
    string s = "";
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (!root) {
            return res;
        }
        dfs(root, s+to_string(root->val));
        return res;
    }
    
    void dfs(TreeNode* root, string s) {
        if (!root->left && !root->right) {
            res.push_back(s);
            return;
        }
        if (root->left) {
            dfs(root->left, s+"->"+to_string(root->left->val));
        }
        if (root->right) {
            dfs(root->right, s+"->"+to_string(root->right->val));
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
