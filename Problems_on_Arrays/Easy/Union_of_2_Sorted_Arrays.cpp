// Union of 2 Sorted Arrays

// Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.
// Union of two arrays can be defined as the set containing distinct common elements that are present in either of the arrays.

// Examples:

// Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
// Output: [1, 2, 3, 4, 5, 6, 7]
// Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
// Input: a[] = [2, 2, 3, 4, 5], b[] = [1, 1, 2, 3, 4]
// Output: [1, 2, 3, 4, 5]
// Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.
// Input: a[] = [1, 1, 1, 1, 1], b[] = [2, 2, 2, 2, 2]
// Output: [1, 2]
// Explanation: Distinct elements including both the arrays are: 1 2.
// Constraints:
// 1  ≤  a.size(), b.size()  ≤  105
// -109 ≤ a[i], b[i] ≤109

// Brute Force

class Solution
{
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        // code here
        set<int> st;

        for (int n : a)
        {
            st.insert(n);
        }

        for (int x : b)
        {
            st.insert(x);
        }

        vector<int> unionarr;

        for (auto &it : st)
        {
            unionarr.push_back(it);
        }

        return unionarr;
    }
};

// Optimal Approach

class Solution
{
public:
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        // code here
        int n1 = a.size();
        int n2 = b.size();
        vector<int> unionarr;
        int i = 0, j = 0;

        while (i < n1 && j < n2)
        {
            if (a[i] <= b[j])
            {
                if (unionarr.size() == 0 || unionarr.back() != a[i])
                {
                    unionarr.push_back(a[i]);
                }
                i++;
            }
            else
            {
                if (unionarr.size() == 0 || unionarr.back() != b[j])
                {
                    unionarr.push_back(b[j]);
                }
                j++;
            }
        }

        while (i < n1)
        {
            if (unionarr.size() == 0 || unionarr.back() != a[i])
            {
                unionarr.push_back(a[i]);
            }
            i++;
        }

        while (j < n2)
        {
            if (unionarr.size() == 0 || unionarr.back() != b[j])
            {
                unionarr.push_back(b[j]);
            }
            j++;
        }

        return unionarr;
    }
};

//TC-->O(n+m)