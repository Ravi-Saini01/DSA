// 7.Reverse Integer

// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

// Example 1:

// Input: x = 123
// Output: 321
// Example 2:

// Input: x = -123
// Output: -321
// Example 3:

// Input: x = 120
// Output: 21
 

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
};