//
//  main.cpp
//  BinaryTreeTraversal
//
//  Created by 黄启明 on 2018/10/23.
//  Copyright © 2018 Himin. All rights reserved.
//
/*
 递归算法和非递归算法
 
 二叉树遍历：层次遍历
           先(根)序遍历、中序遍历、后序遍历
 */

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // 先序遍历
    void preorderTraversal(TreeNode *root) {
        if (root) {
            cout << root->val << "->";
            preorderTraversal(root->left);
            preorderTraversal(root->right);
        }
    }
    // 中序遍历
    void inorderTraversal(TreeNode *root) {
        if (root) {
            inorderTraversal(root->left);
            cout << root->val << "->";
            inorderTraversal(root->right);
        }
    }
    // 后序遍历
    void postOrderTraversal(TreeNode *root) {
        if (root) {
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            cout << root->val << "->";
        }
    }
    // 层次遍历
    void levelOrderTraversal(TreeNode *root) {
        if (root) {
            queue<TreeNode *> q;
            q.push(root);
            while (!q.empty()) {
                TreeNode *node = q.front();
                cout << node->val << "->";
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                q.pop();
            }
        }
    }
    // 二叉树的节点总数
    int nodeCount(TreeNode *root) {
        if (!root) {
            return 0;
        }
        return 1+nodeCount(root->left)+nodeCount(root->right);
    }
    // 二叉树的深度
    int depthOfTree(TreeNode *root) {
        if (!root) {
            return 0;
        } else {
            return max(depthOfTree(root->left), depthOfTree(root->right))+1;
        }
    }
    // 二叉树的最小深度
    int minDepthOfTree(TreeNode *root) {
        if (!root) {
            return 0;
        } else {
            int leftDepth = minDepthOfTree(root->left);
            int rightDepth = minDepthOfTree(root->right);
            if (leftDepth == 0 || rightDepth == 0) {
                return leftDepth+rightDepth+1;
            }
            return min(leftDepth, rightDepth)+1;
        }
    }
    // 二叉树叶子节点数
    int leafNodeCount(TreeNode *root) {
        if (!root) {
            return 0;
        } else {
            if (!root->left && !root->right) {
                return 1;
            }
            return leafNodeCount(root->left)+leafNodeCount(root->right);
        }
    }
    
    // 二叉树创建
    TreeNode *createTree() {
        TreeNode *p;
        int val;
        cin >> val;
        if (val == 0) {
            p = NULL;
        } else {
            p = new TreeNode(val);
            p->left = createTree();
            p->right = createTree();
        }
        return p;
    }
};

int main(int argc, const char * argv[]) {
    
//    TreeNode *tree = new TreeNode(1);
//    tree->left = new TreeNode(2);
//    tree->right = new TreeNode(3);
//    tree->right->left = new TreeNode(4);
//    tree->right->right = new TreeNode(5);
    
    TreeNode *tree = Solution().createTree();
    
    cout << "节点总数 = " + to_string(Solution().nodeCount(tree)) << endl;
    cout << "二叉树的深度 = " + to_string(Solution().depthOfTree(tree)) << endl;
    cout << "二叉树的最小深度 = " + to_string(Solution().minDepthOfTree(tree)) << endl;
    cout << "二叉树的叶子节点数 = " + to_string(Solution().leafNodeCount(tree)) << endl;
    
    cout << "先序遍历\n";
    Solution().preorderTraversal(tree);
    cout << endl;
    cout << "中序遍历\n";
    Solution().inorderTraversal(tree);
    cout << endl;
    cout << "后序遍历\n";
    Solution().postOrderTraversal(tree);
    cout << endl;
    cout << "层次遍历\n";
    Solution().levelOrderTraversal(tree);
    cout << endl;
    
    return 0;
}



