#pragma once

#include "pch.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return;
        
        invertTree(root->left);
        invertTree(root->right);
        
        TreeNode* Tmp = root->left;
        root->left = root->right;
        root->right = Tmp;

        return root;
    }
};
