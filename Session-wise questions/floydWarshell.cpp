#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n, vector<int>(n, INT_MAX));
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v]=w;
        graph[v][u]=w;
    }
    for(int i=0; i<n; i++){
        graph[i][i]=0;
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(graph[i][k]!=INT_MAX && graph[k][j]!=INT_MAX && graph[i][k]+graph[k][j]<graph[i][j]){
                    graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(graph[i][j]==INT_MAX){
                cout<<"INF ";
            }else{
                cout<<graph[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}