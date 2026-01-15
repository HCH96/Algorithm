#include <iostream>
#include <bits/stdc++.h>
#include <sstream>

using namespace std;

long long N, M, K, Answer;
vector<long long> v;

void Sol(long long CurDay, long long CurMoney, long long CurLoan, long long StockCount)
{
	long long CurPrice = v[CurDay];

	// 마지막 날
	if (CurDay == N - 1)
	{
		CurMoney += CurPrice * StockCount;
		Answer = max(Answer, CurMoney);
		return;
	}


	// 안팔고, 안산다
	Sol(CurDay + 1, CurMoney, CurLoan, StockCount);

	// 팔고, 안산다
	long long NextMoney = CurMoney + StockCount * CurPrice;
	Sol(CurDay + 1, NextMoney, CurLoan, 0);

	// 팔고, 산다
	CurMoney += StockCount * CurPrice;
	StockCount = 0;
	CurMoney -= CurLoan;
	CurLoan = CurMoney * K;
	CurMoney += CurLoan;

	StockCount = CurMoney / CurPrice;
	CurMoney = CurMoney % CurPrice;
	if(StockCount>0)
		Sol(CurDay + 1, CurMoney, CurLoan, StockCount);

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M >> K;
	v.resize(N);

	for (int i = 0; i < N; ++i)
	{
		cin >> v[i];
	}


	Sol(0, M, 0, 0);

	cout << Answer;

	return 0;
}
