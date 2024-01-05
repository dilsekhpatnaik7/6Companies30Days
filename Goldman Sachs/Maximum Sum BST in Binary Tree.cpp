// Problem Link: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/description/

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
class Node {
    public: 
        int maxNode, minNode, maxSum;
        bool isBST;
        Node(int maxNode, int minNode, int maxSum, bool isBST) {
            this->maxNode = maxNode;
            this->minNode = minNode;
            this->maxSum = maxSum;
            this->isBST = isBST;
        }
};

class Solution {
public:
    Node solve(TreeNode* root, int& maxSum) {
        if(!root) return {INT_MIN, INT_MAX, 0, true};

        auto left = solve(root->left, maxSum);
        auto right = solve(root->right, maxSum);

        if(left.isBST && right.isBST && root->val > left.maxNode && root->val < right.minNode) {
            int currentMax = max(root->val, right.maxNode);
            int currentMin = min(root->val, left.minNode);
            int currentSum = root->val + left.maxSum + right.maxSum;
            maxSum = max(maxSum, currentSum);

            return Node(currentMax, currentMin, currentSum, true);
        }

        return Node(INT_MIN, INT_MAX, max(left.maxSum, right.maxSum), false);
    }

    int maxSumBST(TreeNode* root) {
        int maximumSum = 0;
        solve(root, maximumSum);
        return maximumSum;
    }
};