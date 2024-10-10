
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int,int> m;
        TreeNode* root = new TreeNode(preorder[0]);


        for (int i = 0; i < inorder.size(); ++i)
        {
            m[inorder[i]] = i;
        }

        for (int i = 1; i < preorder.size(); ++i)
        {
            TreeNode* Cur = root;
            
            int target = preorder[i];
            int index = m[target];
            bool IsAdded = false;

            while (!IsAdded)
            {
                // 왼쪽 Subtree에 있는지 확인
                if (index < m[Cur->val])
                {
                    if (Cur->left == nullptr)
                    {
                        TreeNode* LeftChild = new TreeNode(target);
                        Cur->left = LeftChild;
                        IsAdded = true;
                    }
                    else
                    {
                        Cur = Cur->left;
                    }
                }
                // 오른쪽 SubTree에 있는지 확인
                else
                {
                    if (Cur->right == nullptr)
                    {
                        TreeNode* RightChild = new TreeNode(target);
                        Cur->right = RightChild;
                        IsAdded = true;
                    }
                    else
                    {
                        Cur = Cur->right;
                    }
                }
            }
        }

        return root;
    }
};