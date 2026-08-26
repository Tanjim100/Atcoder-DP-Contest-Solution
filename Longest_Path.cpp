#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cinvec(v,n) for(int i=0;i<n;i++){ll x; cin>>x; v.push_back(x);}
#define coutvec(v)  for(auto x : v){cout << x << " ";}cout << endl
#define maxof(v) *max_element(v.begin(), v.end())
#define minof(v) *min_element(v.begin(), v.end())
#define sort(v)   sort(v.begin(), v.end()) 
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define print(v) cout << v << endl

const ll mod = 1e9+7;


ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll nCr(int n, int r)
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
    for (int i = 2; i*i <= n; i++)
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

void make_bitmask(vector< vector<int> > &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        int q = i;
        int j = 0;
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

vector<int> adj[100001];
vector<int> dp(100001);

int dfs(int i)
{
    if(dp[i]) return dp[i];
    for(auto a : adj[i])
    {
        dp[a] = dfs(a);
        dp[i] = max(dp[i], dp[a] + 1);
    }

    return dp[i];
}

void solve()
{
    int n, e;
    cin >> n >> e;

    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for(int i = 1; i <= n; i++)
    {
        dfs(i);
    }

    int ans = 0;
    for(int i = 0; i <= n; i++) ans = max(ans, dp[i]);


    cout << ans << endl;


}

int main()
{
    fast();

    int t=1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
