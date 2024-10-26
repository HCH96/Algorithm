#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    vector<bool> visited(n, false);
    queue<int> q;

    for (int i = 0; i < n; ++i)
    {
        if (visited[i] == false)
        {
            q.push(i);
            visited[i] = true;

            while (!q.empty())
            {
                int Cur = q.front();
                q.pop();

                for (int j = 0; j < n; ++j)
                {
                    if (visited[j] == false && computers[Cur][j] == 1)
                    {
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }

            ++answer;
        }
    }

    return answer;
}