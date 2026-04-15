// 179. Largest Number

// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.

// Since the result may be very large, so you need to return a string instead of an integer.

// Example 1:

// Input: nums = [10,2]
// Output: "210"
// Example 2:

// Input: nums = [3,30,34,5,9]
// Output: "9534330"

// Constraints:

// 1 <= nums.length <= 100
// 0 <= nums[i] <= 109

class Solution
{
public:
    static bool comp(int &a, int &b)
    {
        string s1 = to_string(a);
        string s2 = to_string(b);

        return (s1 + s2) > (s2 + s1);
    };

    string largestNumber(vector<int> &nums)
    {

        sort(nums.begin(), nums.end(), comp);

        if (nums[0] == 0)
        {
            return "0";
        }

        string result;

        for (int &num : nums)
        {
            result += to_string(num);
        }
        return result;
    }
};
// Tc-->O(N∗K∗logN)