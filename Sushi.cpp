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
#define double(val, precision) fixed << setprecision(precision) << val 

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
vector<int> cnt(4);

double dp[305][305][305];
int vis[305][305][305];

double func(int c1, int c2, int c3)
{
    if(c1 == 0 && c2 == 0 && c3 == 0) return 0;

    if(vis[c1][c2][c3]) return dp[c1][c2][c3];

    vis[c1][c2][c3] = 1;

    double ans = 1.;
    double p1 = 1. * c1 / n;
    double p2 = 1. * c2 / n;
    double p3 = 1. * c3 / n;
    
    if(c1 > 0) ans += p1 * func(c1-1, c2, c3);
    if(c2 > 0) ans += p2 * func(c1+1, c2-1, c3);
    if(c3 > 0) ans += p3 * func(c1, c2+1, c3-1);
    
    double p0 = 1. * (n - c1 - c2 - c3) / n;

    ans /= (1. - p0);

    return dp[c1][c2][c3] = ans;
}

void solve()
{
    cin >> n;
    vector<int> v;
    cinvec(v, n);

    for(int i = 0; i < n; i++)
    {
        cnt[v[i]]++;
    }

    double ans = func(cnt[1], cnt[2], cnt[3]);

    cout << double(ans, 16) << endl;

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


// Explanation: 


// Expected value, E(x) = sumof(x * P(x))      P(x) = probability of x
// In a dice, there are 6 values, {1, 2, 3, 4, 5, 6}
// and probability of each value is 1/6

// if dice is rolled one then E(x) = 1*1/6 + 2*1/6 + 3*1/6 + 4*1/6 + 5*1/6 + 6*1/6
// this example is Terminal Experiment because after one operation or one roll, it is terminated 

// but our problem is cyclic state problem(non terminal experiment)
// lets, c1 mean 1, c2 means 2, c3 means 3 and c0 means 0
// so a{c1, c2, c3, c0} where ci = count of i in vector v

// Expected Value Eqn:
// 1. a:{c1-1, c2, c3, c0+1}
// 2. a:{c1+1, c2-1, c3, c0}
// 3. a:{c1, c2+1, c3-1, c0}
// 4. a:{c1, c2, c3, c0}


// Final Recurrence: 
// ans = E(c1, c2, c3)
// e1 = E(c1-1, c2, c3)
// e2 = E(c1+1, c2-1, c3)
// e3 = E(c1, c2+1, c3-1)
// p1 = c1/n
// p2 = c2/n
// p3 = c3/n
// p0 = (n - c1 - c2 - c3)/n

// => ans = 1 + p1*e1 + p2*e2 + p3*e3 + p0*ans 
// => ans(1-p0) = 1 + p1*e1 + p2*e2 + p3*e3
// => ans = (1 + p1*e1 + p2*e2 + p3*e3) / (1-p0)


// Time: O(n^3)
// Space: O(n^3)