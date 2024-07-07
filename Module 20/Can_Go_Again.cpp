
#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int u;
    int v;
    int w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> v;

    while (e--)
    {
        int a, b;
        long long int w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        v.push_back(ed);
    }

   long long  int dis[n + 1];
    long long int INF = 1e18;

    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }

    int s;
    cin >> s;
    dis[s] = 0;

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            Edge ed = v[j];
            int a = ed.u;
            int b = ed.v;
            int w = ed.w;
            if (dis[a] != INF && dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }

    bool cycle = false;
    for (int j = 0; j < v.size(); j++)
    {
        Edge ed = v[j];
        int a = ed.u;
        int b = ed.v;
        int w = ed.w;
        if (dis[a] != INF && dis[a] + w < dis[b])
        {
            cycle = true;
            break;
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        int D;
        cin >> D;
        if (!cycle)
        {
            if (dis[D] == INF)
            {
                cout << "Not Possible" << endl;
            }
            else
            {
                cout << dis[D] << endl;
            }
        }
        else
        {
            cout << "Negative Cycle Detected" << endl;
            return 0;
        }
    }

    return 0;
}
