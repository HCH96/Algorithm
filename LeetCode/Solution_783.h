#pragma once
#include "pch.h"

class Solution {
public:
    int tmp;

    int minDiffInBST(TreeNode* root) {
        tmp = INT_MAX;

        int ans = INT_MAX;
        inorder(root, ans);

        return ans;
    }

    void inorder(TreeNode* root, int& ans)
    {
        if (root->left)
            inorder(root->left, ans);

        ans = min(ans, abs(root->val - tmp));
        tmp = root->val;

        if (root->right)
            inorder(root->right, ans);
    }

};