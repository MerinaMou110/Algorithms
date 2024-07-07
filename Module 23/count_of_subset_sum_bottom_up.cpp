// input: 4
// 1 4 3 6
// 13
// output: YES
// sum banano possible hbe kina

// input:
//  6
//  1 2 3 4 5 6
//  7
// output:
//  1 0 0 0 0 0 0 0
//  1 1 0 0 0 0 0 0
//  1 1 1 1 0 0 0 0
//  1 1 1 2 1 1 1 0
//  1 1 1 2 2 2 2 2
//  1 1 1 2 2 3 3 3
//  1 1 1 2 2 3 4 4

// fillup kora possible kina

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int s;
    cin >> s;
    int dp[n + 1][s + 1];
    dp[0][0] = 1;
    for (int i = 1; i <= s; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (a[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - a[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    // if (dp[n][s])
    //     cout << "YES" << endl;
    // else
    //     cout << "NO" << endl;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}