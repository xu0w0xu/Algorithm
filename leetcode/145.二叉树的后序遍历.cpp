#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorder(TreeNode* root, vector<int>& res) {
        if(root == NULL) return {};
        postorder(root->left, res);
        postorder(root->right, res);
        res.push_back(root->val);
        return res;
    }

    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> res;
        postorder(root, res);
        return res;
    }
};
// @lc code=end

