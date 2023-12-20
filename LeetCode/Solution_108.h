#pragma once

#include "pch.h"
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {

        TreeNode* ans = nullptr;

        for (int i = 0; i < nums.size(); ++i)
        {
            ans = insertNode(ans, nums[i]);
        }

        return ans;
    }

    TreeNode* insertNode(TreeNode* root, int val)
    {
        if (root == nullptr)
        {
            root = new TreeNode(val);
            return root;
        }

        if (val < root->val)
        {
            root->left = insertNode(root->left, val);
        }
        else if (val > root->val)
        {
            root->right = insertNode(root->right, val);
        }

        // Rebalancing

        // 높이 확인
        int leftHeight = GetHeight(root->left);
        int rightHeight = GetHeight(root->right);
        int diff = rightHeight - leftHeight;


        // 오른쪽 서브트리의 높이가 2이상
        if (diff > 1)
        {
            if (val < root->right->val)
            {
                root->right = Rotate_Right(root->right);
                return Rotate_Left(root);
            }
            else
            {
                return Rotate_Left(root);
            }
        }
        // 왼쪽 서브트리의 높이가 2이상
        else if (diff < -1)
        {
            if (val > root->left->val)
            {
                root->left = Rotate_Left(root->left);
                return Rotate_Right(root);

            }
            else
            {
                return Rotate_Right(root);
            }
        }

        return root;
    }

    int GetHeight(TreeNode* CurNode)
    {
        if (CurNode == nullptr)
            return 0;

        return max(GetHeight(CurNode->left), GetHeight(CurNode->right)) + 1;
    }

    TreeNode* Rotate_Left(TreeNode* Node)
    {
        TreeNode* rightChild = Node->right;
        Node->right = rightChild->left;

        rightChild->left = Node;

        return rightChild;
    }

    TreeNode* Rotate_Right(TreeNode* Node)
    {
        TreeNode* LeftChild = Node->left;
        Node->left = LeftChild->right;

        LeftChild->right = Node;

        return LeftChild;
    }

};