

// 10
// 2 3 5 10 1 4 6 8 9 15

//output: 1 2 3 4 5 6 8 9 10 15

#include <bits/stdc++.h>
using namespace std;
void merge_sort(int a[], int l, int m, int r)
{
    int leftSize = m - l + 1;
    int rightSize = r - m;
    int L[leftSize];
    int R[rightSize];
    int k = 0; 
    for (int i = l; i <= m; i++)
    {
        L[k] = a[i];
        k++;
    }
    k = 0;
    for (int i = m + 1; i <= r; i++)
    {
        R[k] = a[i];
        k++;
    }
    int i=0,j=0;
    int cur=l;
   while(i<leftSize && j<rightSize)
   {
    if(L[i]<=R[j]){
          a[cur]=L[i];
          i++;
    }
    else{
        a[cur]=R[j];
        j++;
    }
    cur++;
   }
   while(i<leftSize){
    a[cur]=L[i];
    i++;
    cur++;
   }
   while(j<rightSize){
    a[cur]=R[j];
    j++;
    cur++;
   }

}


//complexity nlogN
void divide(int a[],int l,int r)
{
    if(l<r)
    {
        int mid=(l+r)/2;
        divide(a,l,mid);
        divide(a,mid+1,r);
        merge_sort(a,l,mid,r);
    }
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
 divide(a,0,n-1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
//space complexity o(n);
//auxoliary space complexity o(n);