// //input
// 4
// 1 5 3 2
// 5 2 4 3
// 7
// output:
// dp[n][s]=8

// full array:
// 0 0 0 0 0 0 0 0
// 0 0 0 0 0 1 1 1
// 0 0 5 5 5 5 5 6
// 0 0 5 5 5 5 8 8
// 0 0 5 5 5 7 8 8


#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int v[n], w[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    int s;
    cin >> s;
    int dp[n + 1][s + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (w[i - 1] <= j)
            {
                dp[i][j] = max(v[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
            }

            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
   // cout<<dp[n][s]<<endl;
   //puro array dekhte caile
   for(int i=0;i<=n;i++){
    for(int j=0;j<=s;j++){
        cout<<dp[i][j]<<" ";
    
    }
    cout<<endl;
   }
    return 0;
}