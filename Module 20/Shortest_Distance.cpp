// #include <bits/stdc++.h>
// using namespace std;
// const int N = 105+2;

// long long int dis[N]; // store the minimum distance
// vector<pair<int, int>> v[N];
// bool vis[N];
// long long int n, e;
// void dijkstra(int s)
// {

//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

//     pq.push({0, s});
//     dis[s] = 0;
//     while (!pq.empty())
//     {
//         pair<int, int> parent = pq.top();
//         pq.pop();
//         int parentNode = parent.second;
//         if (vis[parentNode])
//         {
//             continue;
//         }
//         vis[parentNode] = true;
//        long long  int parentCost = parent.first;

//         for (auto child : v[parentNode])
//         {
//             int childNode = child.first;
//             long long int childCost = child.second;

//             if (parentCost + childCost < dis[childNode])
//             {
//                 dis[childNode] = parentCost + childCost;
//                 pq.push({dis[childNode], childNode});
//             }
//         }
//     }
// }
// int main()
// {
//     // int n, e;
//     cin >> n >> e;
//     while (e--)
//     {
//         long long int a, b, w;
//         cin >> a >> b >> w;
//         v[a].push_back({b, w});

//     }

//     long long int q;
//     cin >> q;
//     while (q--)
//     {
//         int x, y;
//         cin >> x >> y;
//         for (int i = 1; i <= n; i++)
//         {
//             vis[i] = false;
//         }
//         for (int i = 1; i <= n; i++)
//         {
//             dis[i] = INT_MAX;
//         }
//         dijkstra(x);
//         if (dis[y] == INT_MAX)
//         {
//             cout << -1 << endl;
//         }
//         else
//         {
//             cout << dis[y] << endl;
//         }
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e18;
int main()
{
    int n, e;
    cin >> n >> e;
   long long int dis[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dis[i][j] = INF;
            if (i == j)
                dis[i][j] = 0;
        }
    }
    while (e--)
    {
        int a, b;
        long long int w;
        cin >> a >> b >> w;
        dis[a][b] = min(dis[a][b],w);
        
    }
   
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        if (dis[x][y] == INF)
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dis[x][y] << endl;
        }
    }
}
