// 264. Ugly Number II

// An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.

// Given an integer n, return the nth ugly number.

// Example 1:

// Input: n = 10
// Output: 12
// Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
// Example 2:

// Input: n = 1
// Output: 1
// Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.

// Constraints:

// 1 <= n <= 1690

// Brute force

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if (n == 1)
            return 1;

        int num = 2, cnt = 1;

        while (true)
        {
            if (cnt == n)
            {
                break;
            }
            int num2 = num;
            bool uglyno = true;
            while (num2 > 1)
            {
                if (num2 % 2 == 0)
                {
                    num2 /= 2;
                }
                else if (num2 % 3 == 0)
                {
                    num2 /= 3;
                }
                else if (num2 % 5 == 0)
                {
                    num2 /= 5;
                }
                else
                {
                    uglyno = false;
                    break;
                }
            }
            if (uglyno == true)
            {

                cnt++;
            }
            num++;
        }
        return num - 1;
    }
};
// TC-->O(nlogn)

// Optimal Approach
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        if (n == 1)
            return 1;

        int num = 2, cnt = 1;

        while (cnt < n)
        {
            int num2 = num;
            bool uglyno = true;

            while (num2 % 2 == 0)
                num2 /= 2;
            while (num2 % 3 == 0)
                num2 /= 3;
            while (num2 % 5 == 0)
                num2 /= 5;

            if (num2 != 1)
                uglyno = false;

            if (uglyno)
                cnt++;

            num++;
        }

        return num - 1;
    }
};
// TC-->O(nlog n)

// Best Approach (Using DP)

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> dp(n + 1);
        // dp[i]==ith ugly number

        dp[1] = 1;
        int i2, i3, i5;
        i2 = i3 = i5 = 1;

        for (int i = 2; i <= n; i++)
        {
            int i2th_ugly = dp[i2] * 2;
            int i3th_ugly = dp[i3] * 3;
            int i5th_ugly = dp[i5] * 5;

            dp[i] = min({i2th_ugly, i3th_ugly, i5th_ugly});

            if (dp[i] == i2th_ugly)
            {
                i2++;
            }

            if (dp[i] == i3th_ugly)
            {
                i3++;
            }

            if (dp[i] == i5th_ugly)
            {
                i5++;
            }
        }
        return dp[n];
    }
};
// TC-->O(n)
// SC-->O(n)