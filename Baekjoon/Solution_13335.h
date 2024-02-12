#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

int T, M, N, K, B, W, L;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 트럭의 수, 다리의 길이, 최대 하중
	cin >> N >> W >> L;

	vector<int> v(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	int CurWeight = 0;
	int CurTime = 0;
	int CurIdx = 0;

	// 남은 시간, 무게
	queue<pair<int, int>> q;

	CurWeight += v[CurIdx];
	q.push({ W - 1, v[CurIdx] });
	++CurIdx;
	++CurTime;

	while (!q.empty())
	{
		// 다리위에 있는 트럭 업데이트
		int qSize = q.size();
		for (int i = 0; i < qSize; ++i)
		{
			int time = q.front().first;
			int weight = q.front().second;
			q.pop();
			if (time > 0)
			{
				q.push({ time - 1,weight });
			}
			else
			{
				CurWeight -= weight;
			}
		}

		// 다리위에 트럭이 올라갈 공간이 있는 경우
		if (q.size() < W && CurIdx < N && CurWeight + v[CurIdx] <= L)
		{
			CurWeight += v[CurIdx];
			q.push({ W - 1, v[CurIdx] });
			++CurIdx;
		}


		++CurTime;
	}


	cout << CurTime;

	return 0;
}

