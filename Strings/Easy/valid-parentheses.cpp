// https://leetcode.com/problems/valid-parentheses


// Using Stack - T.C. - O(n), S.C. - O(n)
// if s[i] is open bracket then push it in the stack otherwise compare for the closing bracket of s[i] with the top of stack.
// if both are same then pop out and move ahead but if not same then retrurn false. At the end if stack is empty then return true.

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else
            {
                if (st.empty())
                    return false;

                if ((s[i] == ')' && st.top() == '(') || (s[i] == '}' && st.top() == '{') || (s[i] == ']' && st.top() == '['))
                    st.pop();
                else
                    return false;
            }
        }
        if (st.empty())
            return true;
        else
            return false;
    }
};