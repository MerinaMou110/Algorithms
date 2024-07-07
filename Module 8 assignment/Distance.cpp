#include <bits/stdc++.h>
using namespace std;
const int n = 1e5 + 3;
vector<int> adj[n];

void Distance(int S, int D)
{
    bool visited[n] = {false};
    int level[n] = {0};
    queue<int> q;
    q.push(S);
    visited[S] = true;
    level[S] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (u == D)
        {
            cout << level[u] << endl;
            return;
        }
        for (int v : adj[u])
        {
            if (visited[v] == false)
            {
                q.push(v);
                visited[v] = true;
                level[v] = level[u] + 1;
            }
        }
    }
    cout << "-1" << endl;
}
int main()
{
    int N, E;
    cin >> N >> E;
    for (int i = 0; i < E; i++)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    int Q;
    cin >> Q;
    while (Q--)
    {
        int S, D;
        cin >> S >> D;
        Distance(S, D);
    }

    return 0;
}
