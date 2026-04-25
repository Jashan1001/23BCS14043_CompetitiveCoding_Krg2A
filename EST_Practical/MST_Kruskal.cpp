#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px == py) return false;

        if(rank[px] < rank[py])
            parent[px] = py;
        else if(rank[px] > rank[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
};

int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<vector<int>> edges;

    // Step 1: Create all edges
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int cost = abs(points[i][0] - points[j][0]) +
                       abs(points[i][1] - points[j][1]);
            edges.push_back({cost, i, j});
        }
    }

    // Step 2: Sort edges
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    int mstCost = 0;

    // Step 3: Kruskal
    for(auto &e : edges) {
        int cost = e[0];
        int u = e[1];
        int v = e[2];

        if(dsu.unite(u, v)) {
            mstCost += cost;
        }
    }

    return mstCost;
}

int main() {
    vector<vector<int>> points = {
        {0,0}, {2,2}, {3,10}, {5,2}, {7,0}
    };

    cout << minCostConnectPoints(points);
}