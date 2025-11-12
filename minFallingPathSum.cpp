#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        if (i == m - 1) return grid[i][j];

        if (dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;

        for (int k = 0; k < n; k++) {
            if (k != j) {
                mini = min(mini, grid[i][j] + helper(i + 1, k, grid, dp));
            }
        }

        return dp[i][j] = mini;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int mini = INT_MAX;

        for (int j = 0; j < n; j++) {
            mini = min(mini, helper(0, j, grid, dp));
        }

        return mini;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Minimum Falling Path Sum II = " << sol.minFallingPathSum(grid) << endl;
    return 0;
}
