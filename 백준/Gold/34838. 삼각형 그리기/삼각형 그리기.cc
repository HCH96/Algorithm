#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll N;
    while (cin >> N) {
        // nC3 계산: n * (n-1) * (n-2) / 6
        ll nC3 = N * (N - 1) * (N - 2) / 6;

        ll answer;
        if (N % 3 != 0) {
            // 정삼각형이 없는 경우
            answer = nC3 / N;
        } else {
            // 정삼각형이 있는 경우
            // 공식: (nC3 + 2/3 * N) / N
            answer = (nC3 + (2 * N / 3)) / N;
        }

        cout << answer << "\n";
    }

    return 0;
}