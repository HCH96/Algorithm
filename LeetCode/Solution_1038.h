#pragma once

#include "pch.h"

class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        Sol(root,0);

        return root;
    }

    int Sol(TreeNode* Node, int PrevGst)
    {
        int RetVal = Node->val;

        if (Node->right != nullptr)
            RetVal += Sol(Node->right, PrevGst);

        Node->val = RetVal + PrevGst;

        if(Node->left !=nullptr)
            RetVal += Sol(Node->left, Node->val);

        return RetVal;
    }
    

};
