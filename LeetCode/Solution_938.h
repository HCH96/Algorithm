#pragma once

#include "pch.h"

class Solution {
public:
    void Sol(TreeNode* Node, int low, int high, int& ans)
    {
        if (Node == nullptr)
            return;

        if (Node->val >= low && Node->val <= high)
            ans += Node->val;

        if (Node->val >= low)
            Sol(Node->left, low, high, ans);

        if (Node->val <= high)
            Sol(Node->right, low, high, ans);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        Sol(root, low, high, ans);

        return ans;
    }
};