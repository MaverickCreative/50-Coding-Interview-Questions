//Given an n x m array where all rows and columns are in sorted order, write a
//function to determine whether the array contains an element x.

//Solution -->

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = -1;
        if(matrix.size() == 0 || matrix[0].size() == 0)
        {
            return false;
        }
        for(int i=0;i<matrix.size();i++)
        {
            if(matrix[i][matrix[0].size()-1]<target)
            {
                continue;
            }
            else
            {
                row = i;
                break;
            }
        }
        if(row!=-1)
        {
            for(int i=0;i<matrix[0].size();i++)
            {
                if(matrix[row][i]==target)
                {
                    return true;
                }
            }
        }
        return false;
    }
};