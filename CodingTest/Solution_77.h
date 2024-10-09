#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    vector<vector<int>> ans;

    void DFS(vector<int>& tmp, int Cur, int n, int k)
    {
        if (tmp.size() == k)
        {
            ans.push_back(tmp);
            return;
        }
       
        for (int i = Cur + 1; i <= n; ++i)
        {
            tmp.push_back(i);
            DFS(tmp, i, n, k);
            tmp.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;

        DFS(tmp, 0, n, k);

        return ans;
    }
};