// Problem Link: https://leetcode.com/problems/trim-a-binary-search-tree/description/

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
class Solution {
public:
    TreeNode* solve(TreeNode* root, int low, int high) {
        if(!root) return root;

        if(root->val <= high && root->val >= low) {
            root->left = solve(root->left, low, high);
            root->right = solve(root->right, low, high);
        } else if(root->val < low) root = solve(root->right, low, high);
        else if(root->val > high) root = solve(root->left, low, high);

        return root;
    }

    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if(!root) return root;

        return solve(root, low, high);
    }
};