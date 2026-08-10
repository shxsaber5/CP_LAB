#include <bits/stdc++.h>
using namespace std;

long long value[105], wt[105];
long long dp[100005];

int main()
{
    int n, W;
    cin >> n >> W;

    for (int i = 0; i < n; i++)
    {
        cin >> wt[i] >> value[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = W; j >= wt[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - wt[i]] + value[i]);
        }
    }

    cout << dp[W] << endl;

    return 0;
}
