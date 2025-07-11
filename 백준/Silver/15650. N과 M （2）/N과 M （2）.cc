#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, M;

void Sol(vector<int>& v, int cur)
{
	if (v.size() == M)
	{
		for (int i = 0; i < M; ++i)
		{
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = cur; i <= N; ++i)
	{
		v.push_back(i);
		Sol(v, i+1);
		v.pop_back();
	}

}

int main() {

	cin >> N >> M;

	vector<int> v;

	Sol(v, 1);

	return 0;
}