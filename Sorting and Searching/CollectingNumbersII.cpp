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

int main()
{
//freopen("input.txt", "r", stdin); // redirects standard input
//	freopen("output.txt", "w", stdout); // redirects standard output
FAST
ll tc=1;
//cin>>tc;
while(tc--)
{
int n, k, a, b, pass = 1;
     cin >> n >> k;
     vector<int> numbers(n + 1);
     vector<int> location(n + 1);
     map<int, int> numpairs;
     for (int i = 1; i <= n; i++)
     {
          cin >> numbers[i];
          location[numbers[i]] = i;
     }

     for (int i = 1; i < n; i++)
          if (location[i + 1] < location[i])
               pass++;
     

     while (k--)
     {
          cin >> a >> b;

          // put the numbers but we will check for boundary cond

          if (numbers[a] - 1 >= 1)
               numpairs.insert({numbers[a] - 1, numbers[a]});
          if (numbers[a] + 1 <= n)
               numpairs.insert({numbers[a], numbers[a] + 1});
          if (numbers[b] - 1 >= 1)
               numpairs.insert({numbers[b] - 1, numbers[b]});
          if (numbers[b] + 1 <= n)
               numpairs.insert({numbers[b], numbers[b] + 1});

          for (auto it = numpairs.begin(); it != numpairs.end(); it++)
               if (location[it->first] > location[it->second])
                    pass--;
//JO PEHLE KE THE INVERSION UNKO HATAYA AUR BAAD ME SWAPPING KE BAAD USKO ADD KIA
          swap(numbers[a], numbers[b]);
          location[numbers[a]] = a;
          location[numbers[b]] = b;

          for (auto it = numpairs.begin(); it != numpairs.end(); it++)
               if (location[it->first] > location[it->second])
                    pass++;

          cout << pass << "\n";
          numpairs.clear();
     }
}



return 0;

}