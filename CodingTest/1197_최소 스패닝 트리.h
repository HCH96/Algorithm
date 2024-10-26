#include <bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

int findParent(int node, vector<int>& parent) {
    if (parent[node] != node) {
        parent[node] = findParent(parent[node], parent);
    }
    return parent[node];
}

void unionSets(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = findParent(a, parent);
    b = findParent(b, parent);
    if (a != b) {
        if (rank[a] < rank[b]) {
            swap(a, b);
        }
        parent[b] = a;
        if (rank[a] == rank[b]) {
            rank[a]++;
        }
    }
}

int main() {
    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);
    for (int i = 0; i < E; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].u--; // 1-based indexing to 0-based indexing
        edges[i].v--;
    }

    // 간선을 가중치 기준으로 오름차순 정렬
    sort(edges.begin(), edges.end());

    // 유니온-파인드 초기화
    vector<int> parent(V);
    vector<int> rank(V, 0);
    for (int i = 0; i < V; ++i) {
        parent[i] = i;
    }

    int mst_weight = 0;
    int edges_used = 0;

    // 최소 스패닝 트리 만들기
    for (const auto& edge : edges) {
        if (findParent(edge.u, parent) != findParent(edge.v, parent)) {
            unionSets(edge.u, edge.v, parent, rank);
            mst_weight += edge.weight;
            edges_used++;
            if (edges_used == V - 1) break; // MST 완성
        }
    }

    cout << mst_weight << endl;

    return 0;
}