#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 6;
vector<int> adj[N];
int dis[N];
bool visited[N];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
        int parent = q.front();
        
        q.pop();
        cout<<parent<<" ";
        for (int v : adj[parent])
        {
            if(!visited[v]){
                q.push(v);
                visited[v]=true;
                dis[v]=dis[parent]+1;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs(1);
    for(int i=1;i<=n;i++){
        cout<<"node"<<i<<":"<<dis[i]<<endl;
    }
    return 0;
}