#include<bits/stdc++.h>
using namespace std;
const int N=1e5+6;

int dis[N];
vector<pair<int,int>>v[N];
void dijkstra(int s){
    queue<int>q;
    q.push(s);
    dis[s]=0;
    while(!q.empty())
    {
        int parent=q.front();
        q.pop();
        for(auto child:v[parent]){
            int childNode=child.first;
            int weight=child.second;
            if(dis[parent]+weight<dis[childNode]){
                dis[childNode]=dis[parent]+weight;
                q.push(childNode);
            }
           
        }
    }
}
int main()
{ 
    int n,e;
    cin>>n>>e;
    while(e--){
        int a,b,w;
        cin>>a>>b>>w;
        v[a].push_back({b,w});
        v[b].push_back({a,w});
    } 
      for(int i=1;i<=n;i++){
        dis[i]=INT_MAX;
      }
      dijkstra(1);
      
      for(int i=1;i<=n;i++){
        cout<<i <<":"<<dis[i]<<endl;
      }
    return 0;
}