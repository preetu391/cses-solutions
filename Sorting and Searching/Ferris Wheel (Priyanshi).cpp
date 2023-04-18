#include <bits/stdc++.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define mll map<ll, ll>
#define mii map<int, int>
#define mllc map<ll, char>
#define mcll map<char, ll>
#define fl(i, n) for (int i = 0; i < n; i++)
#define rl(i, m, n) for (int i = n; i >= m; i--)
#define ff first
#define ss second
#define sz size
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;
const int mod2 = 998244353;
const long long inf = 1e9;
const long double PI = 3.141592653589793;
vector<long long> primes;

bool isPrime(int n)
{
  if (n <= 1)
    return false;
  if (n <= 3)
    return true;
  if (n % 2 == 0 || n % 3 == 0)
    return false;

  for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0)
      return false;
  return true;
}
void makePrimes()
{
  for (int i = 2; i < inf; i++)
  {
    if (isPrime(i))
      primes.push_back(i);
  }
}

// Operator overloads
template <typename T1, typename T2> // cin >> pair<T1, T2>
istream &operator>>(istream &istream, pair<T1, T2> &p)
{
  return (istream >> p.first >> p.second);
}
template <typename T> // cin >> vector<T>
istream &operator>>(istream &istream, vector<T> &v)
{
  for (auto &it : v)
    cin >> it;
  return istream;
}
template <typename T1, typename T2> // cout << pair<T1, T2>
ostream &operator<<(ostream &ostream, const pair<T1, T2> &p)
{
  return (ostream << p.first << " " << p.second);
}
template <typename T> // cout << vector<T>
ostream &operator<<(ostream &ostream, const vector<T> &c)
{
  for (auto &it : c)
    cout << it << " ";
  return ostream;
}

// Utility functions
template <typename T>
void print(T &&t) { cout << t << "\n"; }
void printarr(ll arr[], ll n)
{
  fl(i, n) cout << arr[i] << " ";
  cout << "\n";
}
template <typename T>
void printvec(vector<T> v)
{
  ll n = v.size();
  fl(i, n) cout << v[i] << " ";
  cout << "\n";
}
template <typename T>
ll sumvec(vector<T> v)
{
  ll n = v.size();
  ll s = 0;
  fl(i, n) s += v[i];
  return s;
}

/************************ JUNGFREUD :") **************************/

ll getmsb(ll num)
{
  ll nof = floor(log2(num)) + 1;
  return nof;
}
bool getbit(ll num, ll pos)
{
  return num & (1 << pos);
}
bool cmp(pair<ll, ll> a, pair<ll, ll> b)
{
  if (a.second > b.second)
  {
    return true;
  }
  else if (a.second == b.second)
  {
    if (a.first > b.first)
      return true;
    return false;
  }
  return false;
}

void solution()
{
}

ll fact(ll num)
{
  ll k = 1;
  for (ll i = 1; i <= num; i++)
  {
    k *= (i);
    k %= num;
  }
  return k;
}

bool isfes(ll m, ll n)
{
  ll a = fact(m);
  ll b = fact(m - 1);
  if ((a + b) % n == 0)
    return true;
  return false;
}

ll sumOfMaximumOfSubsets(vector<long long> arr, int N)
{
    sort(arr.begin(), arr.end(), greater<int>());

    int sum = arr[0];
    for (int i = 1; i < N; i++)
    {
      sum = (2 * sum + arr[i]);
    }
    return sum;
}

signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  // ll t;
  // cin >> t;
  // for (int l = 1; l <= t; l++)
  // {
    ll n,x;
    cin>>n>>x;
    vector<ll> a(n);
    cin>>a;
    sort(a.begin(),a.end());
    ll i=0, j=n-1;
    ll ans=0;
    while(i<=j){
      if(a[i]+a[j]<=x){
        ans++;
        i++;
        j--;
      }else if(a[i]+a[j]>x){
        j--;
        ans++;
      }else if(i==j){
        ans++;
        i++;
      }
    }
    cout<<ans;
  // }
  return 0;
}
