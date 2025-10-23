#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int T, N, M, K, W, R, Q, S, G, P;

int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };


long long Cross(pair<long long, long long> A, pair<long long, long long> B)
{ 
    return A.first * B.second - A.second * B.first;
}

int ccw(pair<long long, long long> A, pair<long long, long long> B, pair<long long, long long> C)
{
    pair<long long, long long> AB = { B.first - A.first, B.second - A.second };
    pair<long long, long long> BC = { C.first - B.first, C.second - B.second };

    long long CrossRes = AB.first * BC.second - AB.second * BC.first;

    if (CrossRes > 0)
    {
        return 1;
    }
    else if (CrossRes < 0)
    {
        return -1;
    }
    else
    {
        return 0;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pair<long long, long long> A, B, C, D;
    cin >> A.first >> A.second;
    cin >> B.first >> B.second;
    cin >> C.first >> C.second;
    cin >> D.first >> D.second;
    

    pair<long long, long long> d1 = { B.first - A.first, B.second - A.second };
    pair<long long, long long> d2 = { D.first - C.first, D.second - C.second };

    long long CrossValue = Cross(d1, d2);
    int Answer = -1;


    // 기울기가 같다.
    if (CrossValue == 0)
    {
        pair<long long, long long> Tmp = { C.first - A.first, C.second - A.second };
        long long CrossTmp = Cross(d1, Tmp);

        // 같은 직선위에 있다.
        if (CrossTmp == 0)
        {
            long long MinXL1 = min(A.first, B.first);
            long long MaxXL1 = max(A.first, B.first);
            
            long long MinXL2 = min(C.first, D.first);
            long long MaxXL2 = max(C.first, D.first);

            long long MinYL1 = min(A.second, B.second);
            long long MaxYL1 = max(A.second, B.second);

            long long MinYL2 = min(C.second, D.second);
            long long MaxYL2 = max(C.second, D.second);

            // 범위가 겹친다.
            if (max(MinXL1, MinXL2) <= min(MaxXL1, MaxXL2)
                && max(MinYL1, MinYL2) <= min(MaxYL1, MaxYL2))
            {
                Answer = 1;
            }
            // 범위가 겹치지 않는다.
            else
            {
                Answer = 0;
            }
        }
        // 같은 직선위에 있지 않다.
        else
        {
            Answer = 0;
        }
    }
    // 기울기가 다르다.
    else
    {
        int ccwABC = ccw(A, B, C);
        int ccwABD = ccw(A, B, D);
        int ccwCDA = ccw(C, D, A);
        int ccwCDB = ccw(C, D, B);

        if (ccwABC * ccwABD == 1 || ccwCDA * ccwCDB == 1)
        {
            Answer = 0;
        }
        else
        {
            Answer = 1;
        }
    }

    cout << Answer;

    return 0;
}