#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int a[], int l, int r, int k)
{
    int count=0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (a[mid] == k)
        {
            if(a[mid+1]==k || a[mid-1]==k)
                return true;
        }
        else if (k < a[mid])
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cin >> k;

    if (binarySearch(a, 0, n - 1, k))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}