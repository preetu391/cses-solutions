#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define sp fixed<<setprecision
#define ld long double
#define ll long long
#define PI acos(-1)
#define all(x) (x).begin(), (x).end()
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
 
ll mod=1e9+7;
ll power(ll a,ll b)
{
 ll ans=1ll;
   while(b>0)
  {
       if(b&1)
        ans=(ans*a);
      b=b>>1;
     a=(a*a);
  }
return ans;
}
 
ll powerm(ll a,ll b)
{
 ll ans=1ll;
   while(b>0)
  {
       if(b&1)
        ans=(ans*a)%mod;
      b=b>>1;
     a=(a*a)%mod;
  }
return ans;
}
 
int dp[200001];
int d[200001];
int f=0;
void DFS(int v,vector<vector<int> > & adj,vector<int> &vis){
    vis[v]=1;
    int c=0;
 
    for(int k:adj[v]){
        if(vis[k]==0){
 
                DFS(k,adj,vis);
 
 
            c=max(c,1+dp[k]);
 
        }
    }
    dp[v]=c;
 
 
 
}
int j=0,z=INT_MIN;
void DFS(int v,vector<vector<int> > & adj,vector<int> &vis,int cc){
    vis[v]=1;
    int c=0;
if(j<cc){
      j=cc;
    f=v;
}
    for(int k:adj[v]){
        if(vis[k]==0){
 
                DFS(k,adj,vis,cc+1);
 
 
            c=max(c,1+dp[k]);
 
        }
    }
    dp[v]=c;
 
 
 
}
int main()
{
//freopen("input.txt", "r", stdin); // redirects standard input
//	freopen("output.txt", "w", stdout); // redirects standard output
FAST
ll tc=1;
//cin>>tc;
while(tc--)
{int n;
cin>>n;
vector<vector<int> >v(n);
for(int i=0;i<n-1;i++){
    int x,y;
    cin>>x>>y;
    v[x-1].push_back(y-1);
 
    v[y-1].push_back(x-1);
}
 
vector<int> vis(n,0);
DFS(0,v,vis,0);
 
 
memset(dp,0,200001);
vector<int> vis1(n,0);
 
 
DFS(f,v,vis1);
 
    cout<<dp[f];
 
 
 
 
 
 
}
 
 
 
}
