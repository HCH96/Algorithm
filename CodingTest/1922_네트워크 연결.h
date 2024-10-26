#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int primMST(int V, vector<vector<pair<int, int>>>& graph) {
    vector<bool> inMST(V, false); // MST�� ���� ����
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    int mst_cost = 0; // MST �� ���
    int edges_used = 0; // ���� ���� ��

    // ���� ���� ���� (0�� ����)
    pq.push({ 0, 0 }); // {����ġ, ����}

    while (!pq.empty() && edges_used < V) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // �̹� MST�� ���Ե� �����̸� ����
        if (inMST[u]) continue;

        // ���� ������ MST�� �߰�
        inMST[u] = true;
        mst_cost += weight;
        edges_used++;

        // ���� ������ ������ ������ ó��
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

    // �׷��� �Է�
    for (int i = 0; i < E; ++i) {
        int u, v, weight;
        cin >> u >> v >> weight;
        u--; v--; // 0-based index�� ��ȯ
        graph[u].push_back({ v, weight });
        graph[v].push_back({ u, weight });
    }

    int mst_cost = primMST(V, graph);
    cout << mst_cost << endl;

    return 0;
}