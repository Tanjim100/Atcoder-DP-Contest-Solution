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

int n;
vector<vector<int> > v;

int dp[100005][3];

int func(int i, int j)
{
    if(i < 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int ans;

    int p, q;
    if(j == 0) p = 1, q = 2;
    if(j == 1) p = 0, q = 2;
    if(j == 2) p = 0, q = 1;

    ans = max(func(i-1, p), func(i-1, q)) + v[i][j];

    return dp[i][j] = ans;
}

void solve()
{
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> d;
        d.push_back(a);
        d.push_back(b);
        d.push_back(c);

        v.push_back(d);
        
    }

    memset(dp, -1, sizeof(dp));

    int ans = 0;
    for(int i = 0; i < 3; i++)
    {
        ans = max(ans, func(n-1, i));
    }

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
