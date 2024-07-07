// #include <bits/stdc++.h>
// using namespace std;
// const int n = 1e5 + 3;
// vector<int> adj[n];
// bool visited[n];
// int level[n];
// void Level(int S, int l)
// {
//     bool visited[n] = {false};
//     int level[n] = {0};
//     queue<int> q;
//     vector<int> v1;
//     q.push(S);
//     visited[S] = true;
//     bool flag = false;
//     level[S] = 0;
//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();
//         if (l == level[u])
//         {
//             v1.push_back(u);
//             flag = true;
//         }

//         for (int v : adj[u])
//         {
//             if (visited[v] == false)
//             {
//                 q.push(v);
//                 visited[v] = true;
//                 level[v] = level[u] + 1;
//             }
//         }
//     }

//     if (flag == true)
//     {

//         sort(v1.begin(), v1.end());
//         for (int i : v1)
//         {
//             cout << i << " ";
//         }
//     }
//     else
//     {
//         cout << "-1" << endl;
//     }
// }
// int main()
// {
//     int N, E, L;
//     cin >> N >> E;
//     for (int i = 0; i < E; i++)
//     {
//         int A, B;
//         cin >> A >> B;
//         adj[A].push_back(B);
//         adj[B].push_back(A);
//     }
//     cin >> L;
//     Level(0, L);

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;
const int n = 1e5 + 3;
vector<int> adj[n];
bool visited[n];
int level[n];
void Level(int S, int l)
{
    bool visited[n] = {false};
    int level[n] = {0};
    queue<int> q;
    vector<int> v1;
    q.push(S);
    visited[S] = true;
    bool flag = false;
    level[S] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (l == level[u])
        {
            v1.push_back(u);
            flag = true;
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

    if (flag == true)
    {

        sort(v1.begin(), v1.end());
        for (int i : v1)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "-1" << endl;
    }
}
int main()
{
    int N, E, L;
    cin >> N >> E;
    for (int i = 0; i < E; i++)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    cin >> L;
    Level(0, L);

    return 0;
}
