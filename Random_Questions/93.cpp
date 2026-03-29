// 93. Restore IP Addresses

// A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.

// For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
// Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.

// Example 1:

// Input: s = "25525511135"
// Output: ["255.255.11.135","255.255.111.35"]
// Example 2:

// Input: s = "0000"
// Output: ["0.0.0.0"]
// Example 3:

// Input: s = "101023"
// Output: ["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

// Constraints:

// 1 <= s.length <= 20
// s consists of digits only.

class Solution
{
public:
    bool isvalid(string str)
    {
        if (str[0] == '0')
        {
            return false;
        }

        int val = stoi(str);

        return val <= 255;
    }
    void solve(string &s, int idx, int part, string curr, int n,
               vector<string> &result)
    {
        if (idx == n && part == 4)
        {
            curr.pop_back();
            result.push_back(curr);
        }

        if (idx + 1 <= n)
        {
            solve(s, idx + 1, part + 1, curr + s.substr(idx, 1) + ".", n,
                  result);
        }

        if (idx + 2 <= n && isvalid(s.substr(idx, 2)))
        {
            solve(s, idx + 2, part + 1, curr + s.substr(idx, 2) + ".", n,
                  result);
        }

        if (idx + 3 <= n && isvalid(s.substr(idx, 3)))
        {
            solve(s, idx + 3, part + 1, curr + s.substr(idx, 3) + ".", n,
                  result);
        }
    }
    vector<string> restoreIpAddresses(string s)
    {
        int n = s.length();
        vector<string> result;
        if (n > 12)
            return result;

        int part = 0;
        string curr = "";

        solve(s, 0, part, curr, n, result);

        return result;
    }
};

//TC-->O(3^4)-->O(1)