//Given a 2D array of 1s and 0s, find the largest square subarray of all 1s.

//Solution -->

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
        {
            return 0;
        }
        vector<vector<int>> output(matrix.size() , vector<int> (matrix[0].size(), 0));
        for(int i=0;i<matrix.size();i++)
        {
            output[i][0] = matrix[i][0] - '0';
        }
        for(int i=0;i<matrix[0].size();i++)
        {
             output[0][i] = matrix[0][i] - '0';
        }
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(i == 0 || j == 0)
                {
                    continue;
                }
                if(matrix[i][j] == '1')
                {
                    int ans = min(min(output[i-1][j],output[i][j-1]),output[i-1][j-1]);
                    ans += 1;
                    output[i][j] = ans;
                }
            }
        }
        int max = 0;
        for(int i=0;i<output.size();i++)
        {
            for(int j=0;j<output[0].size();j++)
            {
                    if(max<output[i][j])
                    {
                        max = output[i][j];
                    }
            }
        }
        return max*max;
    }
};


//Solutions only contain the heart of the program as they were solved on Leetcode so as to make sure they
//work on every test case;