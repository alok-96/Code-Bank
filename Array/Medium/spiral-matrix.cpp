// https://leetcode.com/problems/spiral-matrix

// T.C. -> O(m*n), S.C. -> O(m+n)
// Brute force approach 

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int row = matrix.size(), col = matrix[0].size();
       int startingRow = 0, endingRow = row-1;
       int startingCol = 0, endingCol = col-1;
       vector<int>v;

       while(startingRow <= endingRow && startingCol <= endingCol)
       {
           for(int i=startingCol; i<=endingCol; i++)
           {
               v.push_back(matrix[startingRow][i]);
           }
           startingRow++;

           for(int i=startingRow; i<=endingRow; i++)
           {
               v.push_back(matrix[i][endingCol]);
           }
           endingCol--;

           if(startingRow <= endingRow)               // if there is only single row
           {
                for(int i=endingCol; i>=startingCol; i--)
                {
                    v.push_back(matrix[endingRow][i]);
                }
                endingRow--;
           }

            if(startingCol <=  endingCol)            // if there is only single column
            {
                for(int i=endingRow; i>=startingRow; i--)
                {
                    v.push_back(matrix[i][startingCol]);
                }
                startingCol++;
            }
       }

        return v;
    }
};