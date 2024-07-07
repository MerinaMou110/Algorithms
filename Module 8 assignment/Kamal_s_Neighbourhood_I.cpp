#include <bits/stdc++.h>
using namespace std;
const int n = 22;
vector<int> adj[n];

int main()
{
    int N, E, K;
    cin >> N >> E;
    for (int i = 0; i < E; i++)
    {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    cin >> K;

    int cnt = 0;
    for (int i : adj[K])
    {
        cnt++;
    }
    cout << cnt << endl;

    return 0;
}
