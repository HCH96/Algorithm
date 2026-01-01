#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <unordered_set>

using namespace std;

int N, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    string s;
    cin >> s;

    int Size = s.size();
    int head = 0;
    int tail = 0;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == 'H')
            ++head;
        else
            ++tail;
    }

    vector<bool> visited(Size+1);

    visited[head] = true;
    queue<vector<int>> q;
    q.push({ head ,0 });
    while (!q.empty())
    {
        int CurHead = q.front()[0];
        int CurTail = Size - CurHead;
        int CurCount = q.front()[1];
        q.pop();

        if (CurHead == 0 && CurTail == Size)
        {
            cout << CurCount;
            return 0;
        }

        for (int i = 0; i <= K; ++i)
        {
            int HeadFlip = i;
            int TailFlip = K - i;
            
            if (HeadFlip > CurHead || TailFlip > CurTail)
                continue;

            int NextHead = CurHead + TailFlip - HeadFlip;
            int NextTail = CurTail + HeadFlip - TailFlip;

            if (NextHead<0 || NextHead >Size || NextTail<0 || NextTail >Size)
                continue;

            if (visited[NextHead] == false)
            {
                visited[NextHead] = true;
                q.push({ NextHead ,CurCount + 1 });
            }
        }


    }

    cout << -1;

    return 0;
}
