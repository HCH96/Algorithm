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

	// Ʈ���� ��, �ٸ��� ����, �ִ� ����
	cin >> N >> W >> L;

	vector<int> v(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}

	int CurWeight = 0;
	int CurTime = 0;
	int CurIdx = 0;

	// ���� �ð�, ����
	queue<pair<int, int>> q;

	CurWeight += v[CurIdx];
	q.push({ W - 1, v[CurIdx] });
	++CurIdx;
	++CurTime;

	while (!q.empty())
	{
		// �ٸ����� �ִ� Ʈ�� ������Ʈ
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

		// �ٸ����� Ʈ���� �ö� ������ �ִ� ���
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

