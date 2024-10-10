
#include <iostream>
#include <vector>

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
    TreeNode* Sol(vector<int>& nums, int left, int right)
    {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;
        int target = nums[mid];

        TreeNode* Node = new TreeNode(target);
        Node->left = Sol(nums, left, mid - 1);
        Node->right = Sol(nums, mid+1, right);

        return Node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        return Sol(nums, 0, nums.size() - 1);
    }
};