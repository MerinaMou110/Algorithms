#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 6;
const long long int inf = 1e18;
long long int d[N];
int n, m;
vector<pair<int, int>> adj[N];
bool visited[N];
void dijkstra(int s)
{
    for (int i = 1; i <=n; i++)
    {
        d[i] = inf;
    }
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({d[s], s});

    while (!pq.empty())
    {
        pair<int, int> node = pq.top();
        int u = node.second;
        pq.pop();
        visited[u] = true;
        for (auto child : adj[u])
        {
            long long int weight = child.first;
            int v = child.second;
            if (!visited[v])
            {
                if (d[u] + weight < d[v])
                {
                    d[v]=d[u]+weight;
                    pq.push({d[v],v});

                }
            }
        }
    }
}
int main()
{

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    int src = 1;
    dijkstra(src);
    for(int i=1;i<=n;i++){
        cout<<"distance of node "<<i<<":"<<d[i]<<endl;
    }
    return 0;
}