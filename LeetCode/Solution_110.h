#pragma once

#include "pch.h"

class Solution {
public:
    bool ans;

    int GetHeight(TreeNode* Cur)
    {
        if (Cur == nullptr)
            return 0;

        return max(GetHeight(Cur->left), GetHeight(Cur->right)) + 1;
    }

    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;

        int left = GetHeight(root->left);
        int right = GetHeight(root->right);

        if (abs(left - right) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right) ;
    }
};