#include <iostream>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int T, N, M, K, W, R, Q, S, G, P;

int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

vector<int> inorder(N);
vector<int> postorder(N);
unordered_map<int, int> Idx;

void Sol(int InLeft, int InRight, int PostLeft, int PostRight)
{
    if (InLeft > InRight || PostLeft > PostRight)
        return;

    int RootValue = postorder[PostRight];
    int RootIdx = Idx[RootValue];

    cout << RootValue << " ";

    int LeftSubtreeSize = RootIdx - InLeft;

    Sol(InLeft,RootIdx-1,PostLeft, PostLeft + LeftSubtreeSize - 1);
    Sol(RootIdx +1, InRight, PostLeft + LeftSubtreeSize, PostRight - 1);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;


    inorder.resize(N);
    postorder.resize(N);


    for (int i = 0; i < N; ++i)
    {
        cin >> inorder[i];
    }

    for (int i = 0; i < N; ++i)
    {   
        cin >> postorder[i];
    }


    for (int i = 0; i < N; ++i)
    {
        Idx[inorder[i]] = i;
    }

    Sol(0, N - 1, 0, N - 1);


    return 0;
}