#include <bits/stdc++.h>
using namespace std;
class DSU {
    vector<int> parent, size;   
    public:
    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if(parent[u]==u) {
            return u;
        }
        return parent[u] = find(parent[u]);
    }
    void unionsets(int u, int v) {
        int pu = find(u);
        int pv = find(v);
        if(pu==pv){
            return;
        }
        if(size[pu]<size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    int get_size(int u) {
        return size[find(u)];
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        dsu.unionsets(u, v);
    }
    for (int i = 0; i < n; i++) {
        cout << "Size of component containing " << i << ": " << dsu.get_size(i) << endl;
    }
    return 0;
}