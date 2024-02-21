class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int sum = grid[0][0] + grid[0][1] + grid[0][2] + grid[1][1] +
                  grid[2][0] + grid[2][1] + grid[2][2];
        int ans = sum;
        int n = grid.size();
        int m = grid[0].size();
        int i = 2;
        while (i < n) {
            if (i > 2) {
                sum += grid[i][0] + grid[i][1] + grid[i][2] - grid[i - 3][0] -
                       grid[i - 3][1] - grid[i - 3][2] + grid[i - 2][0] +
                       grid[i - 2][2] - grid[i - 1][0] - grid[i - 1][2];
            }
            ans = max(ans, sum);
            int horsum = sum;
            for (int j = 3; j < m; j++) {
                horsum += grid[i - 2][j] + grid[i][j] + grid[i - 1][j - 1] -
                          grid[i - 2][j - 3] - grid[i][j - 3] -
                          grid[i - 1][j - 2];
                ans = max(ans, horsum);
            }
            i++;
        }

        return ans;
    }
};