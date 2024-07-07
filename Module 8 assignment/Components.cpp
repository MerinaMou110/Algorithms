// #include <bits/stdc++.h>
// using namespace std;
// const int n = 1002;
// vector<int> adj[n];
// bool visited[n];

// int bfs(int k)
// {

//     queue<int> q;

//     q.push(k);
//     visited[k] = true;
//     int count = 0;
//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();
//          count++;

//         for (int v : adj[u])
//         {
//             if (visited[v] == false)
//             {
//                 q.push(v);
//                 visited[v] = true;
//             }
//         }
//     }
//     return count;
// }
// int main()
// {
//     int N, E, K;
//     cin >> N >> E;
//     for (int i = 0; i < E; i++)
//     {
//         int A, B;
//         cin >> A >> B;
//         adj[A].push_back(B);
//         adj[B].push_back(A);
//     }
//     int count;
//     vector<int> v1;
//     for (int i = 1; i <n; i++)
//     {

//         if (visited[i])
//             continue;
//         count = bfs(i);
//         if (count > 1)
//             v1.push_back(count);
//     }
//     sort(v1.begin(), v1.end());
//     for (int i : v1)
//     {
//         cout << i << " ";
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
//const int N=1005;
vector<int> adj[1005];
bool check[1005];

void dfs(int u, int &c)
{
    check[u] = true;
    c++;
    for (int v : adj[u])
    {
        if (check[v] == false)
            dfs(v, c);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> v1;
    for (int i = 0; i <1005; i++)
    {
        int c = 0;
        if (check[i] == false)
        {
            dfs(i, c);
            if (c > 1)
                v1.push_back(c);
        }
    }
    sort(v1.begin(), v1.end());
    for (int i : v1)
    {
        cout << i << " ";
    }

    return 0;
}
