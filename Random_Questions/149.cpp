// 149. Max Points on a Line

// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.

// Example 1:

// Input: points = [[1,1],[2,2],[3,3]]
// Output: 3
// Example 2:

// Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// Output: 4

// Constraints:

// 1 <= points.length <= 300
// points[i].length == 2
// -104 <= xi, yi <= 104
// All the points are unique.

// Brute Force (Using Slope Formula)
class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();

        if (n == 1)
            return 1;

        int result = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int cnt = 2;
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                for (int k = 0; k < n; k++)
                {
                    if (k != i && k != j)
                    {
                        int dx_ = points[k][0] - points[i][0];
                        int dy_ = points[k][1] - points[i][1];

                        if (dx_ * dy == dy_ * dx)
                        {
                            cnt++;
                        }
                    }
                }
                result = max(cnt, result);
            }
        }
        return result;
    }
};
// TC-->O(n^3)

// Approach-->2 (Using atan2 STL )

class Solution
{
public:
    int maxPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        if (n == 1)
            return 1;

        if (n == 2)
            return 2;

        int result = 0;

        for (int i = 0; i < n; i++)
        {
            unordered_map<double, int> mp;

            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                auto dy = points[j][1] - points[i][1];
                auto dx = points[j][0] - points[i][0];
                auto slope = atan2(dy, dx);

                mp[slope]++;
            }
            for (auto &it : mp)
            {
                result = max(result, it.second + 1);
            }
        }
        return result;
    }
};

// TC-->O(N^2)
// SC-->O(N)