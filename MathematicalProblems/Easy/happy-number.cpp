// https://leetcode.com/problems/happy-number

// T.C. - O(n), S.C. - O(n)
// in each iteration put that number into the set and if any iteration this number founds in stack of n becomes 1, 
// then terminate the loop and check that if n == 1 then return  true else false

class Solution
{
public:
    int sum(int n)
    {
        int s = 0;
        while (n > 0)
        {
            s += (n % 10) * (n % 10);
            n /= 10;
        }
        return s;
    }

    bool isHappy(int n)
    {
        unordered_set<int> s;

        while (n != 1 && s.find(n) == s.end())
        {
            s.insert(n);
            n = sum(n);
        }

        if (n == 1)
            return true;
        else
            return false;
    }
};