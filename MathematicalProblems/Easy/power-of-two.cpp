// https://leetcode.com/problems/power-of-two


// T.C. -> O(logn), S.C. -> O(1)
// A nummber which is in power of 2 will have only most significant bit as 1 and remaining bits will be 0.
// if n is <= 0 then it will not be in power of two. Otherwise run a loop until n > 1 and 
// divide by two in each iteration. 

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        while( n > 1)
        {
            if(n & 1 != 0)
                return false;
            
            n = n >> 1;
        }
        return true;
    }
};

// T.C. -> O(1), S.C. -> O(1)
// If n is in power of 2 then n & (n-1) will be 0.
// Suppose n = 4
//    1 0 0 
//   &  1 1
// ----------
//    0 0 0
// ----------

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        
        return !(n & (n-1)) ;
    }
};