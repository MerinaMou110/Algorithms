
#include <bits/stdc++.h>
using namespace std;
const int N = 1005;

// store the minimum distance
vector<pair<int, int>> v[N];

long long int n, e;
void dijkstra(int s, int T)
{
    int dis[N];
    bool vis[N]={false};
    for (int i = 1; i <= N; i++)
    {
        dis[i] = INT_MAX;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, s});
    dis[s] = 0;
    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
       long long  int parentNode = parent.second;
        if (vis[parentNode])
        {
            continue;
        }
        vis[parentNode] = true;
        int parentCost = parent.first;

        for (auto child : v[parentNode])
        {
            int childNode = child.first;
           long long int childCost = child.second;

            if (parentCost + childCost < dis[childNode])
            {
                dis[childNode] = parentCost + childCost;
                pq.push({dis[childNode], childNode});
            }
        }
    }
    for (int i = 0; i < T; i++)
    {
       long long int D,DW;
        cin >> D >> DW;

        if (dis[D] <= DW)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}
int main()
{
    cin >> n >> e;
    while (e--)
    {
        long long int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
        //v[b].push_back({a, w});
    }

    long long int s, T;
    cin >> s >> T;
    dijkstra(s, T);

    return 0;
}
