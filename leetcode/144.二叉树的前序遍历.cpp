#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

class Solution {
public:
    vector<int> preorder(TreeNode* root, vector<int>& res) {
        if(root == NULL) return {};
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
        return res;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> res;
        preorder(root, res);
        return res;
    }
};
// @lc code=end

