// https://leetcode.com/problems/add-binary/

// T.C. -> O(max(m,n)), S.C. -> O(max(m,n)+1)
// Used brute force approach using two pointer

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0, i=a.size()-1, j=b.size()-1;

        while(i >= 0 && j >= 0)
        {
            int sum = carry + int(a[i])-48 + int(b[j])-48;
            switch(sum)
            {
                case 0: ans += to_string(0);
                        carry = 0;
                        break;
                case 1: ans += to_string(1);
                        carry = 0;
                        break;
                case 2: ans += to_string(0);
                        carry = 1;
                        break;
                case 3: ans += to_string(1);
                        carry = 1;
                        break;
            }
            i--;
            j--;
        }

        while(i >= 0)
        {
            int sum = carry + int(a[i])-48;
            switch(sum)
            {
                case 0: ans += to_string(0);
                        carry = 0;
                        break;
                case 1: ans += to_string(1);
                        carry = 0;
                        break;
                case 2: ans += to_string(0);
                        carry = 1;
                        break;
            }
            i--;
        }

        while(j >= 0)
        {
            int sum = carry + int(b[j])-48;
            switch(sum)
            {
                case 0: ans += to_string(0);
                        carry = 0;
                        break;
                case 1: ans += to_string(1);
                        carry = 0;
                        break;
                case 2: ans += to_string(0);
                        carry = 1;
                        break;
            }
            j--;
        }

        if(carry > 0)
            ans += to_string(carry);

        reverse(ans.begin(), ans.end());
        return ans;

    }
};


// Not too much complex(consice and small)

class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0, i=a.size()-1, j=b.size()-1;

        while(i >= 0 || j >= 0 || carry == 1)
        {
            if(i >= 0)
            {
                carry += int(a[i]-'0');
                i--;
            }
            if( j >= 0)
            {
                carry += int(b[j]-'0');
                j--;
            }
            
            ans += to_string(carry % 2);
            carry /= 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;

    }
};