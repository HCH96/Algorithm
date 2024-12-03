#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C, N, ans;

int Solution(const vector<int>& Fence, int left, int right)
{
    if (left == right)
        return Fence[left];

    int mid = (left + right) / 2;

    int lhs = Solution(Fence, left, mid);
    int rhs = Solution(Fence, mid + 1, right);

    int ret = max(lhs, rhs);

    int ToLeft = mid;
    int ToRight = mid + 1;
    int CurMinHeight = min(Fence[ToLeft], Fence[ToRight]);

    while (ToLeft >= left && ToRight <= right)
    {
        int Length = ToRight - ToLeft + 1;
        int CurSize = Length * CurMinHeight;

        ret = max(ret, CurSize);

        // 아직 양쪽 모두 더 갈 수 있는 경우
        if (ToLeft > left && ToRight < right)
        {
            if (Fence[ToLeft - 1] >= Fence[ToRight + 1])
            {
                CurMinHeight = min(CurMinHeight, Fence[ToLeft - 1]);
                --ToLeft;
            }
            else
            {
                CurMinHeight = min(CurMinHeight, Fence[ToRight + 1]);
                ++ToRight;
            }
        }
        else if (ToLeft > left || ToRight < right)
        {
            if (ToLeft > left)
            {
                CurMinHeight = min(CurMinHeight, Fence[ToLeft - 1]);
                --ToLeft;
            }
            else
            {
                CurMinHeight = min(CurMinHeight, Fence[ToRight + 1]);
                ++ToRight;
            }
        }
        else
        {
            break;
        }
    }

    return ret;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> C;

    while (C--)
    {
        cin >> N;
        ans = 0;

        vector<int> Fence(N);
        for (int i = 0; i < N; ++i)
        {
            cin >> Fence[i];
        }

        ans = Solution(Fence, 0, Fence.size() - 1);

        cout << ans << endl;
    }

    return 0;
}
