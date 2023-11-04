// https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

// T.C. ->  O(1), S.C. -> O(1)
// Using find function of string,which returns the index of first occurence if ssubstring exits 
// else returns npos if not present

class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = haystack.find(needle);
        if(index >= 0)
            return index;
        else
            return -1;
    }
};