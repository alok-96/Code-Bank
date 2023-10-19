class Solution {
public:
    bool validPalindrome(string s) {
        int i=0, j = s.size()-1;

        while(i < j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                if(j-i == 1)
                return true;
                else
                return false;
            }
        }
        return true;
    }
};