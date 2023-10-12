// https://leetcode.com/problems/set-matrix-zeroes/

// Naive Approach - T.C - O(m*n) S.C. - O(m+n)

// used set to store the index of row and index of columns
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        set<int> row, col;
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[i].size(); j++)
            {
                if (row.find(i) != row.end() || col.find(j) != col.end())
                    matrix[i][j] = 0;
            }
        }
    }
};

// Efficient Approach - T.C. - O(n*m), S.C. - O(1)
// make flag1 true if any row contains 0 at its starting and make flag2 true if any column contains 0 at its starting.
// then traverse from 1st row and 1st column and if current element is 0 then update the first element of this row = 0
// and first element of this column = 0
// again traverse from 1st row and 1st column and if at index [i][j], [i][0] or [0][j] element is 0 then update curr element to 0.
// in the last if flag1 is true then made all the elements of 0th row to 0 and same for flag2 in column
// Note -> why we use flag1 and flag2 varible => if we just start from 0th row and 0th column and if any element of 0th row
//         and 0th column is equal to 0 then it will make all elmnts to 0 of the matrix.

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size(), m = matrix[0].size();
        bool flag1 = false, flag2 = false;

        // finding the row which contains 0 at its starting
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] == 0)
                flag1 = true;
        }

        // finding the column which contains 0 at its starting
        for (int j = 0; j < m; j++)
        {
            if (matrix[0][j] == 0)
                flag2 = true;
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        if (flag1)
        {
            for (int i = 0; i < n; i++)
                matrix[i][0] = 0;
        }

        if (flag2)
        {
            for (int j = 0; j < m; j++)
                matrix[0][j] = 0;
        }
    }
};