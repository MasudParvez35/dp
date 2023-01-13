//zero_one knapsack problem.
#include<iostream>
using namespace std;
int zero_one_knapsack(int val[], int wt[], int n, int w)
{
    if (w == 0 or n == 0) return false;
    
    if (wt[n - 1] <= w)
    {
        return max(val[n - 1] + zero_one_knapsack(val, wt, n, w - wt[n - 1]),
                                zero_one_knapsack(val, wt, n - 1, w));
    }
    else return zero_one_knapsack(val, wt, n - 1, w);
}

int knapsack_Top_Down_DP(int val[], int wt[], int n, int w)
{
    int DP[n+1][w+1], c = 0;
    for (int i = 0; i < n+1; i++)
    {
        for (int j = 0; j < w+1; j++)
        {
            if (i == 0 or j == 0 ) DP[i][j] = 0;
            else if (wt[i - 1] <= j)
            {
                DP[i][j] = max(val[i - 1] + DP[i][j - wt[i - 1]],
                               DP[i - 1][j]);
            }
            else DP[i][j] = DP[i - 1][j];
        }
    }
    return DP[n][w];
}
int main()
{
    int val[] = {50, 100, 120};
    int wt[] = {10, 20, 30}; 
    int w = 40;
    int n = sizeof(val) / sizeof(val[0]);
    cout << knapsack_Top_Down_DP(val, wt, n, w);
    return 0;
}
