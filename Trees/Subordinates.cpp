#include <bits/stdc++.h>
 
using namespace std;
 
 
 
int DFS(int n,vector<vector<int>> &adj,vector<int> &vis,vector<int> &dp ){
 
    vis[n]=1;
    int c=1;
    if(dp[n]!=0){
        return dp[n];
    }
    for(int i=0;i<adj[n].size();i++){
        if(vis[adj[n][i]]==0){
                c+=DFS(adj[n][i],adj,vis,dp);
            vis[n]=1;
        }
    }
 
    return dp[n]=c;
 
 
 
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
int n;
cin>>n;
vector<vector<int> >v(n);
for(int i=0;i<n-1;i++){
    int x;
    cin>>x;
    v[x-1].push_back(i+1);
}
 
vector<int> vis(n,0),ans(n,0);
vis[0]=1;
vector<int> dp(n,0);
dp[0]=DFS(0,v,vis,dp);
for(int i=0;i<n;i++){
    cout<<dp[i]-1<<" ";
}
 
 
 
 
 
 
 
 
 
return 0;
}
