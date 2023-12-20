#pragma once

#include "pch.h"

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        queue<int> q;

        for (int i = 0; i < preorder.size(); ++i)
            q.push(preorder[i]);

        TreeNode* ans = Sol(q, inorder, 0, inorder.size());
        return ans;
    }

    TreeNode* Sol(queue<int>& preorder, vector<int>& inorder, int left, int right)
    {
        int Cur = preorder.front();
        TreeNode* newNode = nullptr;


        for (int i = left; i < right; ++i)
        {
            if (Cur == inorder[i])
            {
                newNode = new TreeNode(Cur);
                preorder.pop();
                newNode->left = Sol(preorder, inorder, left, i);
                newNode->right = Sol(preorder, inorder, left + 1, right);
            }
        }

        return newNode;
    }
};