#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cinvec(v,n) for(int i=0;i<n;i++){ll x; cin>>x; v.push_back(x);}
#define coutvec(v)  for(auto x : v){cout << x << " ";}cout << endl
void fast()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

ll dp[105][100005];

ll knapsack(int i, int weight, vector<int> &w, vector<int> &v)
{
    ll ans = 0;
    if(weight <= 0 or i < 0) return 0;

    if(dp[i][weight] != -1) return dp[i][weight];

    
    if(weight - w[i] >= 0) ans = max(ans, knapsack(i - 1, weight - w[i], w, v) + v[i]);
    ans = max(ans, knapsack(i-1, weight, w, v));
    
    return dp[i][weight] = ans;
}

int main()
{
    fast();
    memset(dp, -1, sizeof(dp));
    ll n, W;
    cin >> n >> W;
    vector<int> w(n), v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> w[i] >> v[i];
    }
    
    cout << knapsack(n, W, w, v) << endl;
    return 0;
}
