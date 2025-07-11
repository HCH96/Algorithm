#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int N;
long long B;

vector<vector<int>> Mul(vector<vector<int>> A, vector<vector<int>> B)
{
	int size = A.size();

	vector<vector<int>> result(size, vector<int>(size, 0));

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			for (int k = 0; k < size; ++k)
			{
				result[i][j] += (A[i][k] * B[k][j]) % 1000;
				result[i][j] %= 1000;
			}
		}
	}
	return result;
}

vector<vector<int>> Sol(vector<vector<int>> matrix, long long square)
{
	if (square == 1)
	{
		return matrix;
	}

	vector<vector<int>> Half = Sol(matrix, square / 2);

	if (square % 2 == 0)
	{
		return Mul(Half, Half);
	}
	else
	{
		return Mul(Mul(Half, Half), matrix);
	}
}



int main() {

	cin >> N >> B;

	vector<vector<int>> arr(N, vector<int>(N));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> arr[i][j];
			arr[i][j] %= 1000;
		}
	}

	vector<vector<int>> Answer = Sol(arr, B);
	int size = Answer.size();

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cout << Answer[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}