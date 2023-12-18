#pragma once

#include "pch.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {

        if (root == nullptr)
            return 0;

        int leftmax = -1;
        leftmax = maxDepth(root->left);

        int rightmax = -1;
        rightmax = maxDepth(root->right);

        if (leftmax > rightmax)
            return leftmax + 1;
        else
            return rightmax + 1;
    }

};