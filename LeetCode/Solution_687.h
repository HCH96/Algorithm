#pragma once

#include "pch.h"

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int ans = 0;

        dfs(root,ans);

        return ans;
    }

    int dfs(TreeNode* Cur, int& ans)
    {
        if (Cur->left == nullptr && Cur->right == nullptr)
            return 0;
        
        int retVal = 0;

        int left = -1;
        if (Cur->left != nullptr)
        {
            left = dfs(Cur->left, ans);
            if (Cur->left->val == Cur->val)
                retVal = left + 1;
        }

        int right = -1;
        if (Cur->right != nullptr)
        {
            right = dfs(Cur->right, ans);
            if (Cur->right->val == Cur->val)
                retVal = max(retVal,right + 1);
        }

        if (left != -1 && right != -1 && Cur->left->val == Cur->val && Cur->right->val == Cur->val)
        {
            ans = max(ans, left + right + 2);
        }

        ans = max(ans, retVal);

        return retVal;
    }
};