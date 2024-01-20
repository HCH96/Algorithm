#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int N, M;
int cntChicken;

vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

vector<int> Comb;

int ans = INT_MAX;

int GetDis()
{
	int retVal = 0;

	for (int i = 0; i < house.size(); ++i)
	{
		int Distance = INT_MAX;

		for (int j = 0; j < Comb.size(); ++j)
		{
			pair<int, int> CurChicken = chicken[Comb[j]];

			int tmp = abs(CurChicken.first - house[i].first) + abs(CurChicken.second - house[i].second);

			if (tmp < Distance)
				Distance = tmp;
		}

		retVal += Distance;
	}

	return retVal;
}



// nCm -> n : cntChicken, m : M (cntChicken개의 치킨 집 중에 m개를 중복없이 뽑는 경우의 수)
void DFS(int Cur)
{
	if (Comb.size() == M)
	{
		int dis = GetDis();
		if (dis < ans)
		{
			ans = dis;
		}
		return;
	}

	for (int i = Cur; i < cntChicken; ++i)
	{
		Comb.push_back(i);
		DFS(i + 1);
		Comb.pop_back();
	}
}



int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int tmp;
			cin >> tmp;

			// House
			if (tmp == 1)
				house.push_back({ i,j });

			// Chicken
			if (tmp == 2)
				chicken.push_back({ i,j });
		}
	}

	cntChicken = chicken.size();

	DFS(0);

	cout << ans;

	return 0;
}