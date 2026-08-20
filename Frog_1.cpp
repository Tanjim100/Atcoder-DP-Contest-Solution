#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cinvec(v,n) for(ll i=0;i<n;i++){ll x; cin>>x; v.push_back(x);}
#define coutvec(v)  for(auto x : v){cout << x << " ";}cout << endl
#define maxof(v) *max_element(v.begin(), v.end())
#define minof(v) *min_element(v.begin(), v.end())
#define sort(v)   sort(v.begin(), v.end()) 

const ll mod = 1e9+7;


ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll nCr(ll n, ll r)
{
    ll p = 1, k = 1;

    if(n - r < r)
    {
        r = n - r;
    }

    if(r)
    {
        while(r)
        {
            p *= n;
            k *= r;

            ll m = gcd(p, k);

            p /= m;
            k /= m;

            n--;
            r--;
        }
    }
    else p = 1;

    return p;
}


bool isPrime(ll n)
{
    bool flag = true;
    for (ll i = 2; i*i <= n; i++)
    {
        if(n % i == 0)
        {
            flag = false;
            return flag;
        } 
    }
    return flag;
}


ll bigmod(ll a, ll b, ll M)
{
    if(b == 0) return 1 % M;
    ll x = bigmod(a, b/2, M);
    x = (x * x) % M;

    if(b & 1) x = (x * a) % M;

    return x;
}

void make_bitmask(vector< vector<ll> > &v)
{
    for (ll i = 0; i < v.size(); i++)
    {
        ll q = i;
        ll j = 0;
        while(q)
        {
            v[i][j] = q % 2;
            q /= 2;
            j++;
        }
    }
    
}


void fast()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

ll dp[100005];

ll func(ll ind, vector<ll> &v, int n)
{
    if(ind == n-1) return 0;

    if(dp[ind] != -1) return dp[ind];

    ll ans = LLONG_MAX;

    ans = min(ans, func(ind + 1, v, n) + abs(v[ind] - v[ind+1]));

    if(ind + 2 < n) ans = min(ans, func(ind + 2, v, n) + abs(v[ind] - v[ind+2]));

    return dp[ind] = ans;
    
}

void solve()
{
    ll n;
    cin >> n;
    vector<ll> v;
    cinvec(v, n);

    for(ll i = 0; i <= n; i++)
    {
        dp[i] = -1;
    }

    ll ans = func(0, v, n);

    cout << ans << endl;
}

int main()
{
    fast();

    ll t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
