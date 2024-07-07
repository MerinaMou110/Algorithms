#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

bool subsetSum(int n, int marks[], int s)
{

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (marks[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - marks[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][s];
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N, M;
        cin >> N >> M;

        int a[N];
        for (int i = 0; i < N; i++)
        {
            cin >> a[i];
        }

        int s = 1000 - M;
        dp[0][0] = true;
        for (int i = 1; i <= s; i++)
        {
            dp[0][i] = false;
        }
        if (subsetSum(N, a, s))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
