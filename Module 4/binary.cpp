#include <bits/stdc++.h>
using namespace std;
const int n = 1e5 + 10;

int a[n];
void binary_search(int N, int k)
{
    int l = 0;
    int r = N - 1;
    bool flag = false;
    int mid;
    while (l <= r)
    {
        mid = (l + r) / 2;

        if (a[mid] == k)
        {
            flag = true;

            break;
        }
        if (k > a[mid])
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
        cout << mid << endl;
    }
    else
    {
        cout << "Not Found" << endl;
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