#include<iostream>
#include<vector>
using namespace std;
int helper(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp)
{
    int m=grid.size();
    int n=grid[0].size();
    if(i>=m ||j>=n ||grid[i][j]==1) return 0;
    if(i==m-1 &&j==n-1)
    {
        return 1;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }

    return dp[i][j]=helper(i+1,j,grid,dp)+helper(i,j+1,grid,dp);
}
int uniquepath(vector<vector<int>>&grid)
{
    int m=grid.size();
    int n=grid[0].size();
    if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
        return 0;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helper(0,0,grid,dp);
}
int main() {
    vector<vector<int>> grid = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    cout << "Number of unique paths: " << uniquepath(grid) << endl;

    return 0;
}