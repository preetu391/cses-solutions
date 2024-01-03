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
vector<vector<int> >v(n+1);
for(int i=0;i<n-1;i++){
    int x,y;
    cin>>x>>y;
    v[x].push_back(y);
 
    v[y].push_back(x);
}
 
queue<int>q;
q.push(1);
int dis[n+1]={0};
dis[1]=1;
int m=1;
int d=1;
while(!q.empty()){
    int val=q.front();
    q.pop();
    for(int k:v[val]){
        if(dis[k]==0){
            dis[k]=1+dis[val];
            if(dis[k]>d){
                d=dis[k];
                m=k;
 
            }
             q.push(k);
        }
    }
}
 
q.push(m);
int dis1[n+1]={0};
dis1[m]=1;
 
d=1;
while(!q.empty()){
    int val=q.front();
    q.pop();
    for(int k:v[val]){
        if(dis1[k]==0){
            dis1[k]=1+dis1[val];
            if(dis1[k]>d){
                d=dis1[k];
                m=k;
 
            }
             q.push(k);
        }
    }
}
q.push(m);
int dis2[n+1]={0};
dis2[m]=1;
 
d=1;
while(!q.empty()){
    int val=q.front();
    q.pop();
    for(int k:v[val]){
        if(dis2[k]==0){
            dis2[k]=1+dis2[val];
            if(dis2[k]>d){
                d=dis2[k];
 
            }
            q.push(k);
        }
    }
}
fr(1,n+1){
cout<<max(dis1[i],dis2[i])-1<<" ";
}
 
 
 
 
 
 
 
 
 
}
 
 
 
 
 
}
