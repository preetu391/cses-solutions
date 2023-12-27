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
{
int n,tsum;
cin>>n>>tsum;
vector<pair<int,int>> v;
 
fr(0,n){
    int x;
    cin>>x;
    v.push_back({x,i+1});
 
 
}
sort(all(v));
 
pair<int,int> ans;
int start=0,end_=v.size()-1;
while(start<end_){
 
 
 
    if(v[start].first+v[end_].first<tsum){
 
        start++;
    }else if(v[start].first+v[end_].first>tsum){
 
        end_--;
    }else{
 
        cout<<v[start].second<<" "<<v[end_].second<<"\n";
        return 0;
    }
}
 
cout<<"IMPOSSIBLE\n";
 
 
 
 
 
 
}
 
 
 
 
 
}
