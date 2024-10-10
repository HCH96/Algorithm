#pragma once

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        if (root == nullptr)
            return 0;

        int leftdia = 0;
        int rightdia = 0;

        if (root->left != nullptr)
        {
            leftdia = diameterOfBinaryTree(root->left);
        }

        if (root->right != nullptr)
        {
            diameterOfBinaryTree(root->right);
        }



    }
};