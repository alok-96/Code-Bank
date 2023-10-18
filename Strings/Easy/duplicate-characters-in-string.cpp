// https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string/

// Naive Approach - T.C. - O(nlogn), S.C. - O(1)
// Using sorting

void printDuplicates(string s)
{
    sort(s.begin(), s.end());

    for(int i=0; i<s.size(); i++)
    {
        count = 1;
        while(i < s.size()-1 && s[i] == s[i+1])
        {
            count++;
            i++;
        }

        if(count > 1)
        cout<<s[i]<<" ";
    } 

}

// Efficient Approach - T.C. - O(n), S.C. - O(n)
// Using hashing

void printDuplicates(string s)
{
    unordered_map<int, int> mp;

    for (auto x : s)
        mp[x]++;

    for (x : mp)
    {
        if (x.second >= 2)
            cout << x.first << endl;
    }
}