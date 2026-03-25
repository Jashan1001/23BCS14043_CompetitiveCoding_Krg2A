#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n);
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    int src=1;
    vector<int> dist(n, INT_MAX);
    dist[src]=0;

    for(int i=0; i<n-1; i++){
        for(int u=0; u<n; u++){
            for(auto [v,w]: graph[u]){
                if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                }
            }
        }
    }

    for(int u=0; u<n; u++){
        for(auto [v,w]: graph[u]){
            if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                cout<<"Negative weight cycle detected!"<<endl;
                return 0;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<dist[i]<<" ";
    }

}