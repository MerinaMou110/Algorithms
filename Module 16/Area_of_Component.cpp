#include <bits/stdc++.h>
#define pi pair<int, int>
using namespace std;
int n, m;

const int N = 1005;
bool vis[N][N];
char a[N][N];
vector<pi> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
bool isValid(int cI, int cJ)
{
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m && a[cI][cJ] == '.')
    {
        return true;
    }
    else
        return false;
}
int dfs(int si, int sj)
{
    int size = 1;
    vis[si][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        pi p = path[i];
        int ci = si + p.first;
        int cj = sj + p.second;
        if (isValid(ci, cj) && !vis[ci][cj])
        {
            size += dfs(ci, cj);
        }
    }
    return size;
}
int main()
{

    cin >> n >> m;
    // int a[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    int minC_size = INT_MAX;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (!vis[i][j] && a[i][j] == '.')
            {
                flag = true;
                int comp_size = dfs(i, j);
                minC_size = min(comp_size, minC_size);
            }
        }
    }
    if (flag)
    {
        cout << minC_size << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}