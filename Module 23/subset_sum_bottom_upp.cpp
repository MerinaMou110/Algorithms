// input: 4
// 1 4 3 6
// 13
// output: YES
//sum banano possible hbe kina

//  4
// 1 4 3 6
// 13
// T F F F F F F F F F F F F F
// T T F F F F F F F F F F F F
// T T F F T T F F F F F F F F
// T T F T T T F T T F F F F F
// T T F T T T T T T T T T F T

//fillup kora possible kina

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
    bool dp[n + 1][s + 1];
    dp[0][0] = true;
    for (int i = 1; i <= s; i++)
    {
        dp[0][i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (a[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
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

    for(int i=0;i<=n;i++){
        for(int j=0;j<=s;j++){
            if(dp[i][j]) cout<<"T ";
             else cout<<"F ";
        }
       cout<<endl;
    }
    return 0;
}