#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
 
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_setpair tree<pair<int,int>, null_type,less<pair<int,int>>, rb_tree_tag,tree_order_statistics_node_update>
 
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define sp fixed<<setprecision
#define ld long double
#define ll long long
#define PI acos(-1)
#define all(x) (x).begin(), (x).end()
#define fr(a,b) for(int i = a; i < b; i++)
#define rfr(a,b) for(int i = a; i >=b; i--)
 
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
 
 void merge(int arr[], int l, int m, int r)
    {
        int i, j, k;
        int n1 = m - l + 1;
        int n2 =  r - m;
 
        /* create temp arrays */
        int L[n1], R[n2];
 
        /* Copy data to temp arrays L[] and R[] */
        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1+ j];
 
        /* Merge the temp arrays back into arr[l..r]*/
        i = 0; // Initial index of first subarray
        j = 0; // Initial index of second subarray
        k = l; // Initial index of merged subarray
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }
 
        /* Copy the remaining elements of L[], if there
           are any */
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
 
        /* Copy the remaining elements of R[], if there
           are any */
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
 
 
    void mergeSort(int arr[], int l, int r)
    {
        if (l < r)
        {
            // Same as (l+r)/2, but avoids overflow for
            // large l and h
            int m = l+(r-l)/2;
 
            // Sort first and second halves
            mergeSort(arr, l, m);
            mergeSort(arr, m+1, r);
 
            merge(arr, l, m, r);
 
        }
    }
    struct range{
    int left,right,index;
     bool operator < (const range &other) const{
        if(left == other.left)
            return right > other.right;
        return left < other.left;
    }
};
 
int main()
{
//freopen("input.txt", "r", stdin); // redirects standard input
//	freopen("output.txt", "w", stdout); // redirects standard output
FAST
ll tc=1;
//cin>>tc;
while(tc--)
{
int n;
cin>>n;
vector<range> v(n);
vector<int> contained(n);
vector<int> contains(n);
ordered_setpair right_boundary;
 
fr(0,n){
    cin>>v[i].left>>v[i].right;
    v[i].index=i;
 
}
sort(all(v));
 
fr(0,n){
right_boundary.insert({v[i].right,-1*i});
contained[v[i].index]=right_boundary.size()-right_boundary.order_of_key({v[i].right,-1*i})-1;
}
right_boundary.clear();
rfr(n-1,0){
    right_boundary.insert({v[i].right,-1*i});
contains[v[i].index]=right_boundary.order_of_key({v[i].right,-1*i});
 
}
fr(0,n){
cout<<contains[i]<<" ";
}
cout<<"\n";
fr(0,n){
cout<<contained[i]<<" ";
}
 
}
 
 
 
 
return 0;
 
}
