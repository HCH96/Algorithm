#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;

public:
    void DFS(vector<int>& nums, vector<int>& Tmp, vector<bool>& visited)
    {
        if (nums.size() == Tmp.size())
        {
            ans.push_back(Tmp);
            return;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            if (visited[i] == false)
            {
                Tmp.push_back(nums[i]);
                visited[i] = true;
                DFS(nums, Tmp, visited);
                visited[i] = false;
                Tmp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        if (nums.size() == 0)
        {
            return ans;
        }

        vector<bool> visited(nums.size(),false);
        vector<int> Tmp;

        DFS(nums, Tmp, visited);

        return ans;
    }
};