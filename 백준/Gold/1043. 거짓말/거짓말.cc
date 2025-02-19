#include <bits/stdc++.h>

using namespace std;

int N, M, K;

vector<int> Parent;

int FindParent(int T)
{
	if (Parent[T] == T)
		return T;

	return Parent[T] = FindParent(Parent[T]);
}

void Union(int A, int B)
{
	A = FindParent(A);
	B = FindParent(B);

	if (A != B)
	{
		Parent[B] = A;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	Parent.resize(N + 1);

	for (int i = 0; i < N + 1; ++i)
	{
		Parent[i] = i;
	}

	vector<int> TruthPeople;

	for (int i = 0; i < K; ++i)
	{
		int p;
		cin >> p;
		TruthPeople.push_back(p);
	}

	vector<vector<int>> Party(M);

	for (int i = 0; i < M; ++i)
	{
		int cnt;
		cin >> cnt;

		if (cnt == 0)
			continue;

		int first;
		cin >> first;
		Party[i].push_back(first);

		for (int j = 1; j < cnt; ++j)
		{
			int People;
			cin >> People;
			Party[i].push_back(People);
			Union(first, People);
		}
	}

	int TruthRoot = TruthPeople.empty() ? -1 : FindParent(TruthPeople[0]);

	for (const auto person : TruthPeople)
	{
		Union(TruthRoot, person);
	}

	int ans = 0;
	for (const auto p : Party)
	{
		if (p.size() == 0)
			continue;

		int leader = FindParent(p[0]);

		if (TruthRoot == -1 || leader != TruthRoot)
			++ans;
	}

	cout << ans;


	return 0;
}
