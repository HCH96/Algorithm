#pragma once
#include "pch.h"

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr)
            return "null ";

        string retVal = to_string(root->val) + " ";

        retVal += serialize(root->left);
        retVal += serialize(root->right);

        return retVal;
    }

    TreeNode* sol(queue<string>& q)
    {
        string tmp = q.front(); q.pop();
        if (tmp == "null")
        {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(tmp));
        root->left = sol(q);
        root->right = sol(q);
        return root;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        queue<string> q;
        string tmp;

        while (ss >> tmp)
        {
            cout << tmp << " ";
            q.push(tmp);
        }

        return sol(q);
    }
};