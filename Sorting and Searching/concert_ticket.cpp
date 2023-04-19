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
#define fr(a,b) for(ll i = a; i < b; i++)
#define rep(i,a,b) for(ll i = a; i < b; i++)

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
    ll n,m;
    cin>>n>>m;
    multiset<ll>mp;
    vector<ll> h(n),t(m);
    fr(0,n){
        cin>>h[i];
       mp.insert(h[i]);
    };
    fr(0,m)cin>>t[i];
  vector<ll> ans;

     fr(0,m){
         auto temp=mp.lower_bound(t[i]);
         if(*temp==t[i]){
             mp.erase(temp);
             ans.push_back(t[i]);
         }else if(temp==mp.end()){

             if(mp.size()==0){


                 ans.push_back(-1);

             }else{
                  temp--;

                 ans.push_back(*temp);
                 mp.erase(temp);

             }

         }
         else{

             if(*temp>t[i]&&temp==(mp.begin())){
ans.push_back(-1);
             }else{
                 temp--;

             ans.push_back(*temp);
              mp.erase(temp);
             }
         }

     }



fr(0,m){
    cout<<ans[i]<<"\n";
}








}





}
