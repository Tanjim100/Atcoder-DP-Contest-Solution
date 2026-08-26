#include <bits/stdc++.h>
using namespace std;
#define ll long long

void fast()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}


int main()
{
    fast();
    int n;
    cin >> n;

    vector<double> v(n+1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    vector<vector<double> > dp(n + 1, vector<double>(n+1));

    dp[0][0] = 1.0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if(j == 0)
            {
                dp[i][j] = dp[i-1][j] * (1-v[i]);
            }
            else 
            {
                dp[i][j] = dp[i-1][j-1]*v[i] + dp[i-1][j]*(1-v[i]);
            }
        }
        
    }

    double ans = 0.0;
    for (int j = n/2 + 1; j <= n; j++)
    {
        ans += dp[n][j];
    }


    cout << fixed << setprecision(10) << ans << endl;
    

    
    
    return 0;
}