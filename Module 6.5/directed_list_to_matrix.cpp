#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int a[N][N];
vector<int>adj[N];

int main()
{
    int v,e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int n,m;
        cin>>n>>m;
           adj[n].push_back(m);  


    }
    //convert adjacency list to adjacency matrix
    for(int i=1;i<=v;i++){
        for(int j:adj[i]){
            a[i][j]=1;
        }
    }
    //print the adjacency matrix
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
              cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}