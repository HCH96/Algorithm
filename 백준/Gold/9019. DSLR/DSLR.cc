#include <bits/stdc++.h>
using namespace std;

int T;
bool visited[10000];

string bfs(int start, int target) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, string>> q;

    visited[start] = true;
    q.push({start, ""});

    while (!q.empty()) {
        int num = q.front().first;
        string oper = q.front().second;
        q.pop();

        if (num == target) {
            return oper;
        }

        // D
        int nextNum = (num * 2) % 10000;
        if (!visited[nextNum]) {
            visited[nextNum] = true;
            q.push({nextNum, oper + "D"});
        }

        // S
        nextNum = (num == 0) ? 9999 : num - 1;
        if (!visited[nextNum]) {
            visited[nextNum] = true;
            q.push({nextNum, oper + "S"});
        }

        // L
        nextNum = (num % 1000) * 10 + (num / 1000); // 왼쪽으로 회전
        if (!visited[nextNum]) {
            visited[nextNum] = true;
            q.push({nextNum, oper + "L"});
        }

        // R
        nextNum = (num % 10) * 1000 + (num / 10); // 오른쪽으로 회전
        if (!visited[nextNum]) {
            visited[nextNum] = true;
            q.push({nextNum, oper + "R"});
        }
    }

    return ""; // 찾을 수 없는 경우
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--) {
        int a, b;
        cin >> a >> b;

        cout << bfs(a, b) << "\n";
    }

    return 0;
}
