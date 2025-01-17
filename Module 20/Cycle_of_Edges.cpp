
// #include <bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 5;
// int parent[N];
// int parentLevel[N];

// void dsu_set(int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         parent[i] = -1;
//         parentLevel[i] = 0;
//     }
// }
// // complexity best case a= O(logn)
// // complexity worst case a=O(logn)
// int dsu_find(int n)
// {
//     while (parent[n] != -1)
//     {
//         n = parent[n];
//     }
//     return n;
// }
// void dsu_union(int a, int b)
// {
//     int leaderA = dsu_find(a);
//     int leaderB = dsu_find(b);
//     if (leaderA != leaderB)
//     {
//         if (parentLevel[leaderA] > parentLevel[leaderB])
//         {
//             parent[leaderB] = leaderA;
//              //parentLevel[leaderB] += parentLevel[leaderA];
//         }
//         else if (parentLevel[leaderB] > parentLevel[leaderA])
//         {
//             parent[leaderA] = leaderB;
//             // parentLevel[leaderA] += parentLevel[leaderB];
//         }
//         else
//         {
//             parent[leaderB] = leaderA;
//             parentLevel[leaderB]++;
//         }
//     }
// }
// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     dsu_set(n);
//     int cnt = 0;
//     while (e--)
//     {
//         int a, b;
//         cin >> a >> b;
//         int leaderA = dsu_find(a);
//         int leaderB = dsu_find(b);
//         if (leaderA == leaderB)
//         {
//             cnt++;
//         }
//         else
//         {
//             dsu_union(a, b);
//         }
//     }
//     cout << cnt << endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int parent[N];

int parentSize[N];
void dsu_set(int n)
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = -1;
        parentSize[i] = 1;
    }
}
// complexity best case a= O(logn)
// complexity worst case a=O(logn)
int dsu_find(int n)
{
    while (parent[n] != -1)
    {
        n = parent[n];
    }
    return n;
}
void dsu_union(int a, int b)
{
    int leaderA = dsu_find(a);
    int leaderB = dsu_find(b);
    if (leaderA != leaderB)
    {
        if (parentSize[leaderA] > parentSize[leaderB])
        {
            // A leader
            parent[leaderB] = leaderA;
            parentSize[leaderA] += parentSize[leaderB];
        }
        else
        {
            parent[leaderA] = leaderB;
            parentSize[leaderB] += parentSize[leaderA];
        }
    }
}
int main()
{

    int n, e;
    cin >> n >> e;
    dsu_set(n);

    int cnt = 0;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA == leaderB)
        {
            cnt++;
        }
        else
        {
            dsu_union(a, b);
        }
    }
    cout << cnt << endl;
    return 0;
}