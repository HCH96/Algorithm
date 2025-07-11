#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<int> arr;

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

	int last = 0;

	for (int i = cur; i < arr.size(); ++i)
	{
		if (arr[i] != last)
		{
			v.push_back(arr[i]);
			last = arr[i];
			Sol(v,i);
			v.pop_back();
		}
	}

}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		int tmp; 
		cin >> tmp;
		arr.push_back(tmp);
	}


	sort(arr.begin(), arr.end());

	vector<int> v;

	Sol(v,0);

	return 0;
}