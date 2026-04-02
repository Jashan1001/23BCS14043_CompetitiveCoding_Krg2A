//kruskal using dsu
#include <bits/stdc++.h>
using namespace std;
class DSU{
    vector<int> parent,size;
    public:
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }
    int find(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u]=find(parent[u]);
    }
    void unionsets(int u,int v){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv){
            return;
        }
        if(size[pu]<size[pv]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
    int get_size(int u){
        return size[find(u)];
    }
};
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> edges(m);
    for(int i=0;i<m;i++){
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
    sort(edges.begin(),edges.end(),[](vector<int>& a,vector<int>& b){
        return a[2]<b[2];
    });
    DSU dsu(n);
    int cost=0;
    for(int i=0;i<m;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        if(dsu.find(u)!=dsu.find(v)){
            dsu.unionsets(u,v);
            cost+=w;
        }
    }
    cout<<cost<<endl;

}