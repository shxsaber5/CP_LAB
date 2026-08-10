#include <bits/stdc++.h>
using namespace std;

int n, W;
int weight[105], value[105];
int dp[105][100005];

int solve(int i, int v)
{
    if (v == 0)
        return 0;

    if (i < 0)
        return W + 1;

    if (dp[i][v] != -1)
        return dp[i][v];

    int not_take = solve(i - 1, v);
    int take = W + 1;

    if (v >= value[i])
    {
        take = solve(i - 1, v - value[i]) + weight[i];
    }

    dp[i][v] = min(not_take, take);

    return dp[i][v];
}

int main()
{
    cin >> n >> W;

    int total_value = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i] >> value[i];
        total_value += value[i];
    }

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= total_value; j++)
        {
            dp[i][j] = -1;
        }
    }

    int answer = 0;

    for (int v = 0; v <= total_value; v++)
    {
        if (solve(n - 1, v) <= W)
            answer = v;
    }

    cout << answer << endl;

    return 0;
}
