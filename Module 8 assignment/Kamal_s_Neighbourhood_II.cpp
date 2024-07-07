#include <bits/stdc++.h>
using namespace std;
const int n = 22;
vector<int> adj[n];
bool visited[n];
int level[n];
void bfs(int k)
{
   
    queue<int> q;

    q.push(k);
    visited[k] = true;
    int count = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (visited[v] == false)
            {
                q.push(v);
                visited[v] = true;
                count++;
            }
        }
    }
    cout << count << endl;
}
int main()
{
    int N, E, K;
    cin >> N >> E;
    for (int i = 0; i < E; i++)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
    }
    cin >> K;

    bfs(K);

    return 0;
}
