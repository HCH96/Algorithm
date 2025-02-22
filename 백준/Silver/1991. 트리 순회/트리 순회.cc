#include <bits/stdc++.h>
#include <unordered_map>

#define ll long long

using namespace std;

int N, M, K, V, X, V1, V2, A, B, C, E, T, W, R;

unordered_map<char, vector<char>> m;

void preorder(const char& Cur)
{
	if (Cur == '.')
		return;

	cout << Cur;
	preorder(m[Cur][0]);
	preorder(m[Cur][1]);
}

void inorder(const char& Cur)
{
	if (Cur == '.')
		return;

	inorder(m[Cur][0]);
	cout << Cur;
	inorder(m[Cur][1]);
}

void postorder(const char& Cur)
{
	if (Cur == '.')
		return;

	postorder(m[Cur][0]);
	postorder(m[Cur][1]);
	cout << Cur;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		char parent, left, right;
		cin >> parent >> left >> right;

		m[parent].push_back(left);
		m[parent].push_back(right);
	}

	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');

	return 0;
}
