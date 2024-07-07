#include <bits/stdc++.h>
using namespace std;
const int n = 1e5 + 10;

int a[n];
void binary_search(int N, int x)
{
    int l = 0;
    int r = N - 1;
    bool flag = false;
    int mid;
    while (l <= r)
    {
        mid = (l + r) / 2;

        if (a[mid] == x)
        {
            if (a[mid] == a[mid + 1] || a[mid] == a[mid - 1])
            {
                flag = true;

                break;
            }
        }
        if (x > a[mid])
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    if (flag == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;
    binary_search(N, k);
    return 0;
}