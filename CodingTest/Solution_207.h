#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    bool ans;
public:
    void DFS(int Cur,const vector<vector<int>>& m,  vector<int>& visited)
    {
        if (ans == false)
        {
            return;
        }

        for (int i = 0; i < m[Cur].size(); ++i)
        {
            int next = m[Cur][i];
            if (visited[next] == 1)
            {
                ans = false;
                return;
            }

            if (visited[next] == 0)
            {
                visited[next] = 1;
                DFS(next, m, visited);
                visited[next] = 2;
            }
        }
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        ans = true;

        vector<int> visited(numCourses, 0);
        vector<vector<int>> m(numCourses, vector<int>());

        for (int i = 0; i < prerequisites.size(); ++i)
        {
            int start = prerequisites[i][0];
            int end = prerequisites[i][1];

            m[start].push_back(end);
        }

        for (int i = 0; i < numCourses; ++i)
        {
            if (ans == true && visited[i] == 0)
            {
                visited[i] = 1;
                DFS(i,m,visited);
                visited[i] = 2;
            }
        }

        return ans;
    }
};