#include<bits/stdc++.h>
using namespace std;
const int N=1e5+6;
vector<int>adj[N];
bool visited[N];
void dfs(int u){
    //section-1:
    //actions just after entering a node
    visited[u]=true;
    cout<<"visiting node: "<<u<<endl;
    for(int v:adj[u]){
        //section -2:
        //actions just after entering a node u
      if(visited[v]==true) continue;
        dfs(v);
       // section-3:
       //actions after exiting a new neighbour


    }
    //section-4
    //actions before exiting a node
}
int main()
{
    int n,m;
    cin>>n>>m;
     
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout<<"visiting array\n";
    for(int i=1;i<=n;i++){
        //visited hoile true....na hoile false
        cout<<"node "<<i<<" status:"<<visited[i]<<endl;
    }
    
    return 0;
}