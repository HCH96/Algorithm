#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int T, N, M, K, W, R, Q, S, G, P;

int dir[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };

int CurIdx = 0;

stack<int> st;


void Sol(vector<int>& InOrder, vector<int>& PostOrder, int Left, int Right)
{
    if (Left > Right)
        return;

    int RootValue = PostOrder[CurIdx--];
    
    
    int RootIdx = find(InOrder.begin() + Left, InOrder.begin() + Right + 1, RootValue) - InOrder.begin();

    Sol(InOrder, PostOrder, RootIdx + 1, Right);
    Sol(InOrder, PostOrder, Left, RootIdx - 1);

    st.push(RootValue);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    vector<int> inorder(N);
    vector<int> postorder(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> inorder[i];
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> postorder[i];
    }

    CurIdx = N - 1;
    
    Sol(inorder, postorder, 0, N - 1);

    while(!st.empty())
    {
		cout << st.top() << " ";
		st.pop();
	}

    return 0;
}