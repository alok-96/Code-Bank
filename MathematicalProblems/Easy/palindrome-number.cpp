// https://leetcode.com/problems/palindrome-number/

//T.C. - O(logn), S.C. - O(1)

class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        long long temp = x, num = 0;
        while (temp > 0)
        {
            num = num * 10 + temp % 10;
            temp /= 10;
        }

        if (num == x)
            return true;
        return false;
    }
};