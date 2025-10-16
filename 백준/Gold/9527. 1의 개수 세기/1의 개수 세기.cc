#include <iostream>
#include <bits/stdc++.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

int T, N, M, K, W, R, Q, S;


long long Sol(long long k)
{
    long long n = k + 1;
    long long RetVal = 0;
    long long BlockSize = 2;
    long long p = 1;
    while (p<n)
    {
        RetVal += (p * (n / BlockSize)) + max(0LL, (n % BlockSize) - BlockSize / 2);

        BlockSize *= 2;
        p *= 2;
    }
    
    return RetVal;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    long long N, M;
    cin >> N >> M;

    cout << Sol(M) - Sol(N-1);

    return 0;
}