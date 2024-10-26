#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int primMST(int V, vector<vector<pair<int, int>>>& graph) {
    vector<bool> inMST(V, false); // MST에 포함 여부
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    int mst_cost = 0; // MST 총 비용
    int edges_used = 0; // 사용된 간선 수

    // 시작 정점 선택 (0번 정점)
    pq.push({ 0, 0 }); // {가중치, 정점}

    while (!pq.empty() && edges_used < V) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // 이미 MST에 포함된 정점이면 무시
        if (inMST[u]) continue;

        // 현재 정점을 MST에 추가
        inMST[u] = true;
        mst_cost += weight;
        edges_used++;

        // 현재 정점에 인접한 정점들 처리
        for (auto& [v, w] : graph[u]) {
            if (!inMST[v]) {
                pq.push({ w, v });
            }
        }
    }

    return mst_cost;
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> graph(V);

    // 그래프 입력
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        u--; v--; // 0-based index로 변환
        graph[u].push_back({ v, weight });
        graph[v].push_back({ u, weight });
    }

    int mst_cost = primMST(V, graph);
    cout << mst_cost << endl;

    return 0;
}