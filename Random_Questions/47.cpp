// 47. Permutations II

// Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

// Example 1:

// Input: nums = [1,1,2]
// Output:
// [[1,1,2],
//  [1,2,1],
//  [2,1,1]]
// Example 2:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Constraints:

// 1 <= nums.length <= 8
// -10 <= nums[i] <= 10

                              //(Approach-->1(using unordered map))

void solve(vector<int> &temp, unordered_map<int, int> &mp, int n, vector<vector<int>> &result)
{

    if (temp.size() == n)
    {
        result.push_back(temp);
        return;
    }

    for (auto &[num, cnt] : mp)
    {
        if (cnt == 0)
            continue;

        // take the element
        temp.push_back(num);
        mp[num]--;

        // explore it
        solve(temp, mp, n, result);

        // backtrack
        temp.pop_back();
        mp[num]++;
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    int n = nums.size();

    vector<vector<int>> result;

    unordered_map<int, int> mp;

    for (int &num : nums)
    {
        mp[num]++;
    }

    vector<int> temp;

    solve(temp, mp, n, result);

    return result;
}

// TC-->O(N*N!)
// SC-->O(N)

                              //(Approach-->2(using unordered set))

class Solution
{
public:
    void solve(int idx, vector<int> &nums, int n, vector<vector<int>> &result)
    {
        if (idx == n)
        {
            result.push_back(nums);
            return;
        }

        unordered_set<int> st;
        for (int i = idx; i < n; i++)
        {
            if (st.count(nums[i]) > 0)
            {
                continue;
            }
            st.insert(nums[i]);

            swap(nums[i], nums[idx]);

            solve(idx + 1, nums, n, result);

            swap(nums[i], nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> result;

        solve(0, nums, n, result);

        return result;
    }
};

// TC-->O(N*N!)
// SC-->O(N)