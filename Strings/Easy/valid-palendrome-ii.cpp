// https://leetcode.com/problems/valid-palindrome-ii/

// T.C. - O(n), S.C. - O(1)
// use two pointer if s[i] == s[j] then i++, j--. if not same then check for the substring removing one character from starting 
// that is it palindrome or not and do the same after removing last character. if anyone is palindrome then return true.

class Solution
{
public:
    bool isPalindrome(string s, int i, int j)
    {
        while (i <= j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
                return false;
        }
        return true;
    }

    bool validPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;

        while (i < j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                bool subStr1 = isPalindrome(s, i, j - 1);
                bool subStr2 = isPalindrome(s, i + 1, j);

                return subStr1 || subStr2;
            }
        }
        return true;
    }
};