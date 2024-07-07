#include<bits/stdc++.h>
using namespace std;
const int N=1e5+6;
vector<int>adj[N];
int visited[N];
vector<int>v1;
void dfs(int n){
        visited[n]=1;
       // vector<int>v1;
        v1.push_back(n);
        for(int v:adj[n]){
            if(visited[v]==0){
            dfs(v);
            }
        }
        // reverse(v1.begin(),v1.end());
        // for(int)
}
int main()
{
    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int v_n,e_n;
        cin>>v_n>>e_n;
        adj[v_n].push_back(e_n);
        adj[e_n].push_back(v_n);

    }
    dfs(1);
    reverse(v1.begin(),v1.end());
    for(int i:v1){
        cout<<i<<" ";
    }

    
    return 0;
}