#pragma once
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;

    sort(routes.begin(), routes.end(), [](const vector<int>& A, const vector<int>& B)
        {
            if (A[0] == B[0])
            {
                return A[1] > B[1];
            }
            return A[0] < B[0];
        });

    vector<int> Cur = { -30000,30000 };

    for (int i = 0; i < routes.size(); ++i)
    {
        if (routes[i][0] > Cur[1])
        {
            ++answer;
            Cur = { routes[i][0],routes[i][1] };
            continue;
        }
            
        Cur[0] = max(routes[i][0], Cur[0]);
        Cur[1] = min(routes[i][1], Cur[1]);
    }


    ++answer;

    return answer;
}