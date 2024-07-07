#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int num[N];
void mergesort(int f,int l,int mid){
    int left_s=mid-f+1;
    int L[left_s+1];
    int right_s=l-mid;
    int R[right_s+1];
    int j=0;
    for(int i=f;i<=mid;i++){
        L[j]=num[i];
        j++;
    }
 j=0;
    for(int i=mid+1;i<=l;i++){
        R[j]=num[i];
        j++;
    }
    L[left_s]=INT_MIN;
    R[right_s]=INT_MIN;
   int ls=0,rs=0;
    for(int i=f;i<=l;i++){
        if(L[ls]>=R[rs])
        {
            num[i]=L[ls];
            ls++;
        }
        else{
            num[i]=R[rs];
            rs++;
        }
    }


}
void divide(int f,int l){
    if(f==l)
    {
        return;
    }
    int mid=(f+l)/2;
    divide(f,mid);
    divide(mid+1,l);
    mergesort(f,l,mid);
}
int main()
{
int n;
cin>>n;
for(int i=0;i<n;i++){
    cin>>num[i];
}
divide(0,n-1);
for(int i=0;i<n;i++){
    cout<<num[i]<<" ";
}
    
    return 0;
}