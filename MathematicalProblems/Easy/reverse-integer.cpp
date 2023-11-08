// https://leetcode.com/problems/reverse-integer/

// T.C. -> O(logn), S.C.-> O(1)
// Write code for reverse a number and check if reverse goes beyond the capacity of integer then return 0.

class Solution {
public:
    int reverse(int x) {
        int rev = 0;

        while(x != 0)
        {
            int last_digit = x % 10;
            if(rev > INT_MAX/10 || rev < INT_MIN/10)
                return 0;
            rev = rev * 10 + last_digit;
            x /= 10;
        }

        return rev;
    }
};