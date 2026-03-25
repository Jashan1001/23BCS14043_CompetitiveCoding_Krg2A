#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string> names(n);
    for(int i=0; i<n; i++){
        cin>>names[i];
    }
    vector<vector<int>> graph(26);
    vector<int> indegree(26, 0);
    for(int i=0; i<n-1; i++){
        string s1=names[i];
        string s2=names[i+1];
        int len=min(s1.size(), s2.size());
        bool found=false;
        for(int j=0; j<len; j++){
            if(s1[j]!=s2[j]){
                graph[s1[j]-'a'].push_back(s2[j]-'a');
                indegree[s2[j]-'a']++;
                found=true;
                break;
            }
        }
        if(!found && s1.size()>s2.size()){
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    queue<int> q;
    for(int i=0; i<26; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    string result="";
    while(!q.empty()){
        int u=q.front();
        q.pop();
        result+=(char)(u+'a');
        for(int v: graph[u]){
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }
    if(result.size()<26){
        cout<<"Impossible"<<endl;
    }else{
        cout<<result<<endl;
    }

}