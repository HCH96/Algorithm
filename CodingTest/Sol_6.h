#include <bits/stdc++.h>

using namespace std;


int findMinWeight(vector<int> weights, int d) {

	priority_queue<int> pq;

	for (int i = 0; i < weights.size(); ++i)
	{
		pq.push(weights[i]);
	}

	while (d > 0)
	{
		int Cur = pq.top();
		pq.pop();

		Cur = Cur - Cur / 2;
		pq.push(Cur);

		--d;
	}

	int ans = 0;

	while (!pq.empty())
	{
		ans += pq.top();
		pq.pop();
	}

	return ans;
}
