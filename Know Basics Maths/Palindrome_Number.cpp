//   9. Palindrome Number

// Given an integer x, return true if x is a palindrome, and false otherwise.

 

// Example 1:

// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.
// Example 2:

// Input: x = -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
// Example 3:

// Input: x = 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
 

// Constraints:

// -231 <= x <= 231 - 1

class Solution{
    public:

    int reverse(int n) {
        int revnum=0;

        while(n!=0)
        {
            int dig=n%10;

            if(revnum<INT_MIN/10 && revnum>INT_MAX/10)
            {
                return 0;
            }
            revnum=revnum*10+dig;
            n/=10;
        }
        return revnum;
    }

    bool isPalindrome(int n) {
        if(n<0) return false;

        int revnum=reverse(n);

        return revnum==n;
    }
};