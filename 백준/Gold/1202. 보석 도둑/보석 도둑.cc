#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int T, N, K, W;

struct cmp
{
    bool operator()(const pair<int, int>& Left, const pair<int, int>& Right)
    {
        if (Left.second == Right.second)
        {
            return Left.first < Right.first;
        }

        return Left.second < Right.second;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K;

    // 무게, 가치
    priority_queue<pair<int, int>, vector<pair<int,int>>, cmp> pq;

    vector<pair<int, int>> jewel;
    vector<int> back;
    long long Answer = 0;

    for (int i = 0; i < N; ++i)
    {
        int w, p;
        cin >> w >> p;

        jewel.push_back({ w,p });
    }

    for (int i = 0; i < K; ++i)
    {
        int w;
        cin >> w;
        back.push_back(w);
    }
    
    sort(back.begin(), back.end());
    sort(jewel.begin(), jewel.end(), [](const pair<int, int>& Left, const pair<int, int>& Right) {

        if (Left.first == Right.first)
        {
            return Left.second < Right.second;
        }
        return Left.first < Right.first;
        });

    int JewelIdx = 0;

    for (auto CurWeight : back)
    {
        while (JewelIdx < jewel.size() && jewel[JewelIdx].first <= CurWeight)
        {
            pq.push(jewel[JewelIdx++]);
        }


        if (!pq.empty())
        {
            Answer += pq.top().second;
            pq.pop();
        }
    }

    cout << Answer;

	return 0;
}