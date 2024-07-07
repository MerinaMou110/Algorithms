
// #include <bits/stdc++.h>
// using namespace std;

// typedef pair<int, int> pii;
// const int N = 200;
// int visited[N][N];
// int level[N][N];

// int n, m;
// vector<pii> direc = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

// bool isValid(int i, int j)
// {
//     return (i >= 0 && i < n && j >= 0 && j < m);
// }

// void bfs(int si, int sj)
// {
//     queue<pii> q;
//     q.push({si, sj});
//     visited[si][sj] = true;
//     level[si][sj] = 0;

//     while (!q.empty())
//     {
//         pii upair = q.front();
//         int i = upair.first;
//         int j = upair.second;
//         q.pop();

//         for (auto d : direc)
//         {
//             int ni = i + d.first;
//             int nj = j + d.second;

//             if (isValid(ni, nj) && !visited[ni][nj])
//             {
//                 q.push({ni, nj});
//                 visited[ni][nj] = true;
//                 level[ni][nj] = level[i][j] + 1;
//             }
//         }
//     }
// }

// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         cin >> n >> m;

//         int si, sj, di, dj;
//         cin >> si >> sj >> di >> dj;

//         for (int i = 0; i < n; i++)
//         {
//             for (int j = 0; j < m; j++)
//             {
//                 level[i][j] = -1;
//                 visited[i][j] = false;
//             }
//         }
//         bfs(si, sj);
//         if (visited[di][dj])
//         {
//             cout << level[di][dj] << endl;
//         }
//         else
//         {
//             cout <<-1<< endl;
//         }
        
//     }
//     return 0;
// }
#include <bits/stdc++.h>

using namespace std;

#define pi pair<int, int>
const int N = 1005;
bool visited[N][N];
int dis[N][N];
int n, m;

vector<pi> path = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};

bool isValid(int cI, int cJ)
{
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m)
        return true;
    else
        return false;
}

void reset_level_vis()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dis[i][j] = 0;
            visited[i][j] = false;
        }
    }
}
void bfs(int si, int sj)
{
    queue<pi> q;
    q.push({si, sj});
    dis[si][sj] = 0;
    visited[si][sj] = true;
    while (!q.empty())
    {
        pi parent = q.front();
        int pI = parent.first;
        int pJ = parent.second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            pi p = path[i];
            int cI = pI + p.first;
            int cJ = pJ + p.second;
            if (isValid(cI, cJ) && !visited[cI][cJ])
            {
                visited[cI][cJ] = true;
                q.push({cI, cJ});
                dis[cI][cJ] = dis[pI][pJ] + 1;
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int si, sj, di, dj;
        cin >> n >> m;
        cin >> si >> sj >> di >> dj;

        reset_level_vis();
        bfs(si, sj);
        
        if (dis[di][dj] == 0 && !(si == di && sj == dj))
            cout << -1 << endl;
        else
            cout << dis[di][dj] << endl;
    }
    return 0;
}