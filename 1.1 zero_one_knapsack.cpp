//zero_one knapsack problem.
#include<iostream>
using namespace std;
int zero_one_knapsack(int val[], int wt[], int n, int w)
{
    if (w == 0 or n == 0) return false;
    
    if (wt[n - 1] <= w)
    {
        return max(val[n - 1] + zero_one_knapsack(val, wt, n-1, w - wt[n-1]),
                                zero_one_knapsack(val, wt, n-1, w));
    }
    else return zero_one_knapsack(val, wt, n-1, w);
}
int knapsack_Top_Down_DP(int val[], int wt[], int n, int w)
{
    int dp[n+1][w+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            if (i == 0 or j == 0 ) dp[i][j] = 0;
            else if (wt[i - 1] <= j)
            {
                dp[i][j] = max(val[i-1] + dp[i-1][j - wt[i-1]], dp[i-1][j]);
            }
            else dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][w];
}
int main()
{
    int val[] = {5,12,8,1};
    int wt[] = {4, 8, 5,3};
    int w = 10;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsack_Top_Down_DP(val, wt, n, w);
    return 0;
}
