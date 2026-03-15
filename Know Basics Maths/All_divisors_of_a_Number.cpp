// All divisors of a Number

// Given an integer n, print all the divisors of N in the ascending order.
 
// Examples:

// Input : n = 20
// Output: 1 2 4 5 10 20
// Explanation: 20 is completely divisible by 1, 2, 4, 5, 10 and 20.
// Input: n = 21191
// Output: 1 21191
// Explanation: As 21191 is a prime number, it has only 2 factors(1 and the number itself).
// Constraints:
// 1 ≤ n ≤ 109

class Solution{
    void print_divisors(int n) {
        vector<int> ls;

        for(int i=1;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                ls.push_back(i);

                if((n/i)!=i)
                {
                    ls.push_back(n/i);
                }
            }
        }
        sort(ls.begin(),ls.end());

        for(auto it : ls)
        {
            cout<<it<<" ";
        }
    }
};