// 97. Interleaving String

// Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

// An interleaving of two strings s and t is a configuration where s and t are divided into n and m substrings respectively, such that:

// s = s1 + s2 + ... + sn
// t = t1 + t2 + ... + tm
// |n - m| <= 1
// The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
// Note: a + b is the concatenation of strings a and b.

// Example 1:

// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
// Explanation: One way to obtain s3 is:
// Split s1 into s1 = "aa" + "bc" + "c", and s2 into s2 = "dbbc" + "a".
// Interleaving the two splits, we get "aa" + "dbbc" + "bc" + "a" + "c" = "aadbbcbcac".
// Since s3 can be obtained by interleaving s1 and s2, we return true.
// Example 2:

// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false
// Explanation: Notice how it is impossible to interleave s2 with any other string to obtain s3.
// Example 3:

// Input: s1 = "", s2 = "", s3 = ""
// Output: true

// Constraints:

// 0 <= s1.length, s2.length <= 100
// 0 <= s3.length <= 200
// s1, s2, and s3 consist of lowercase English letters.

// Follow up: Could you solve it using only O(s2.length) additional memory space?

// Using Recursion
class Solution
{
public:
    bool solve(int i, int j, int k, string &s1, string &s2, string &s3, int n, int m, int N)
    {
        // base case
        if (i == n && j == m && k == N)
        {
            return true;
        }
        if (k >= N)
        {
            return false;
        }
        bool result = false;

        if (s1[i] == s3[k])
        {
            result = solve(i + 1, j, k + 1, s1, s2, s3, n, m, N);
        }
        if (result == true)
        {
            return true;
        }

        if (s2[j] == s3[k])
        {
            result = solve(i, j + 1, k + 1, s1, s2, s3, n, m, N);
        }
        return result;
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.length();
        int m = s2.length();
        int N = s3.length();

        return solve(0, 0, 0, s1, s2, s3, n, m, N);
    }
};

// TC-->O(2^n)

// Using Recursion+Memoization
class Solution
{
public:
    bool solve(int i, int j, int k, string &s1, string &s2, string &s3, int n,
               int m, int N, vector<vector<vector<bool>>> &dp)
    {
        // base case
        if (i == n && j == m && k == N)
        {
            return true;
        }
        if (k >= N)
        {
            return false;
        }
        if (dp[i][j][k] != false)
        {
            return dp[i][j][k];
        }
        bool result = false;

        if (s1[i] == s3[k])
        {
            result = solve(i + 1, j, k + 1, s1, s2, s3, n, m, N, dp);
        }
        if (result == true)
        {
            return dp[i][j][k] = true;
        }

        if (s2[j] == s3[k])
        {
            result = solve(i, j + 1, k + 1, s1, s2, s3, n, m, N, dp);
        }
        return dp[i][j][k] = result;
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.length();
        int m = s2.length();
        int N = s3.length();

        vector<vector<vector<bool>>> dp(
            n + 1, vector<vector<bool>>(m + 1, vector<bool>(N + 1, false)));

        return solve(0, 0, 0, s1, s2, s3, n, m, N, dp);
    }
};

// TC-->O(n*m*N)
// SC-->O(n*m*N)+rest

// Using only two variable(k=i+j)
class Solution
{
public:
    bool solve(int i, int j, string &s1, string &s2, string &s3, int n, int m,
               int N, vector<vector<bool>> &dp)
    {
        // base case
        if (i == n && j == m && i + j == N)
        {
            return true;
        }
        if (i + j >= N)
        {
            return false;
        }
        if (dp[i][j] != false)
        {
            return dp[i][j];
        }
        bool result = false;

        if (s1[i] == s3[i + j])
        {
            result = solve(i + 1, j, s1, s2, s3, n, m, N, dp);
        }
        if (result == true)
        {
            return dp[i][j] = true;
        }

        if (s2[j] == s3[i + j])
        {
            result = solve(i, j + 1, s1, s2, s3, n, m, N, dp);
        }
        return dp[i][j] = result;
    }
    bool isInterleave(string s1, string s2, string s3)
    {
        int n = s1.length();
        int m = s2.length();
        int N = s3.length();

        if (n + m != N)
            return false;

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        return solve(0, 0, s1, s2, s3, n, m, N, dp);
    }
};

// TC--.O(n*m)
// SC-->O(n*m)+rest

// Using Tabulation(Bottom up)
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int m = s1.length();
        int n = s2.length();
        int N = s3.length();
        if (m + n != N)
            return false;

        int t[m + 1][n + 1];
        // t[i][j] = true; //means, s1[0..i] and s2[0...j] interleaves with s3
        // till (i+j)

        // length of s1 = 0, s2 = 0 and s3 = 0 + 0, i.e. 0 . So obviously it's
        // interleaved :-)
        t[0][0] = true;

        // When s1 is of 0 length, we can interleave only when s2 forms s3
        for (int j = 1; j < n + 1; j++)
        {
            t[0][j] = t[0][j - 1] && s2[j - 1] == s3[j - 1];
        }

        // When s2 is of 0 length, we can interleave only if s1 forms s3
        for (int i = 1; i < m + 1; i++)
        {
            t[i][0] = t[i - 1][0] && s1[i - 1] == s3[i - 1];
        }

        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                int k = i + j - 1;

                bool s1_equals_s3 =
                    t[i - 1][j] && s1[i - 1] == s3[k]; // Try with s1

                bool s2_equals_s3 =
                    t[i][j - 1] && s2[j - 1] == s3[k]; // Try with s2

                t[i][j] = s1_equals_s3 || s2_equals_s3;
            }
        }

        return t[m][n];
    }
};
// TC--.O(n*m)
// SC-->O(n*m)