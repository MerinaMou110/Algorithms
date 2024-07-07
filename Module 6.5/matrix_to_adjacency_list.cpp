#include<bits/stdc++.h>
using namespace std;
const int N=1e3+6;
int a[N][N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
           cin>>a[i][j];
        }
    }
    vector<int>list[N];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i][j]==1){
                list[i].push_back(j);
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<"List "<<i<<": ";
        for(int j:list[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }


    
    return 0;
}