#pragma once
#include "pch.h"

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;

        dfs(root, ans);

        return ans;

    }

    int dfs(TreeNode* CurNode, int& ans)
    {
        if (CurNode == nullptr)
            return 0;

        int leftmax = dfs(CurNode->left,ans);
        int rightmax = dfs(CurNode->right,ans);

        if (leftmax + rightmax > ans)
            ans = leftmax + rightmax;

        return max(leftmax, rightmax) + 1;
    }


};