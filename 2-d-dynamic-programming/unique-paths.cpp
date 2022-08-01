class Solution {
public:
    int uniquePaths(int m, int n) {
        /*if (m + n - 2 < 13) {
            vector<int> factorial(m+n-2);
            iota(factorial.begin(), factorial.end(), 1);
            int numerator = accumulate(factorial.begin(), factorial.end(), 1, multiplies<int>());
            int denominator = accumulate(factorial.begin(), factorial.begin() + m - 1, 1, multiplies<int>()) * accumulate(factorial.begin(), factorial.begin() + n -  1, 1, multiplies<int>());
            return numerator / denominator;
        }*/
        int** dp = new int*[m];
        for (size_t i = 0; i < m; i++) {
            dp[i] = new int[n];
        }
        //initialize first row and first column
        for (int i = 0; i < n; i++) {
            dp[0][i] = 1;
        }
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};