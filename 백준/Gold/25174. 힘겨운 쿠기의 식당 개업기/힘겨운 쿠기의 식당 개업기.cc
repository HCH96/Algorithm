#include <iostream>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

int N;

vector<int> xs;
vector<int> ys;
long long Grid[1005][1005];
long long PrefixSum[1005][1005];

struct Info
{
	int x;
	int y;
	int z;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;

	vector<Info> Cats;

	for (int i = 0; i < N; ++i)
	{
		int x, y, z;
		cin >> x >> y >> z;
		
		Cats.push_back({ x,y,z });

	}

	xs.push_back(INT_MIN);
	ys.push_back(INT_MIN);

	for (int i = 0; i < Cats.size(); ++i)
	{
		xs.push_back(Cats[i].x);
		ys.push_back(Cats[i].y);
	}

	sort(xs.begin(), xs.end());
	xs.erase(unique(xs.begin(), xs.end()), xs.end());

	sort(ys.begin(), ys.end());
	ys.erase(unique(ys.begin(), ys.end()), ys.end());



	for (int i = 0; i < Cats.size(); ++i)
	{
		int XIdx = lower_bound(xs.begin(), xs.end(), Cats[i].x) - xs.begin();
		int YIdx = lower_bound(ys.begin(), ys.end(), Cats[i].y) - ys.begin();
		Grid[XIdx][YIdx] += Cats[i].z;
	}

	for (int i = 1; i < ys.size()+1; ++i)
	{
		PrefixSum[0][i] = PrefixSum[0][i - 1] + PrefixSum[0][i];
	}

	for (int i = 1; i < xs.size()+1; ++i)
	{
		PrefixSum[i][0] = PrefixSum[i-1][0] + PrefixSum[i][0];
	}

	for (int i = 1; i < xs.size()+1; ++i)
	{
		for (int j = 1; j < ys.size()+1; ++j)
		{
			PrefixSum[i][j] = PrefixSum[i - 1][j] + PrefixSum[i][j - 1] - PrefixSum[i - 1][j - 1] + Grid[i][j];
		}
	}

	int xMax = xs.size();
	int yMax = ys.size();

	long long Answer = LLONG_MAX;

	for (int i = 0; i < xMax; ++i)
	{
		for (int j = 0; j < yMax; ++j)
		{
			long long S1, S2, S3, S4, All;
			All = PrefixSum[xMax-1][yMax-1];

			S1 = PrefixSum[i][j];
			S2 = PrefixSum[i][yMax] - S1;
			S3 = PrefixSum[xMax][j] - S1;
			S4 = All - S2 - S3 - S1;
			
			long long E = max(max(max(S1, S2), S3), S4) - min(min(min(S1, S2), S3), S4);

			Answer = min(Answer, E);
		}
	}

	cout << Answer;

	return 0;
}
