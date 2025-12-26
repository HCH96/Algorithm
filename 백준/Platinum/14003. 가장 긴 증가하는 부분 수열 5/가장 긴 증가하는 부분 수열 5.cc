#include <iostream>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int N, Answer;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    vector<int> Arr(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> Arr[i];
    }
  
    vector<int> Tail;
    vector<int> TailIdx;
    vector<int> Parent;

    for (int i = 0; i < N; ++i)
    {
        int Cur = Arr[i];

        int Idx = lower_bound(Tail.begin(), Tail.end(), Cur) - Tail.begin();

        if (Idx == Tail.size())
        {
            Tail.push_back(Cur);
            TailIdx.push_back(i);
        }
        else
        {
            Tail[Idx] = Cur;
            TailIdx[Idx] = i;
        }

        if (Idx == 0)
        {
            Parent.push_back(-1);
        }
        else
        {
            Parent.push_back(TailIdx[Idx-1]);
        }

    }

    deque<int> Answer;

    int CurIdx = TailIdx[TailIdx.size() - 1];

    while (CurIdx != -1)
    {
        Answer.push_front(Arr[CurIdx]);
        CurIdx = Parent[CurIdx];
    }
    
    cout << Answer.size() << "\n";

    for (int i = 0; i < Answer.size(); ++i)
    {
        cout << Answer[i] << " ";
    }



    return 0;
}