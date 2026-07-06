class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowL = 0, rowR = matrix.size() - 1;
        if(rowR < 0)
        {
            return -1;
        }
        int colL = 0, colR = matrix[0].size() - 1, rowMean = 0;

        while(rowL <= rowR)
        {
            rowMean = rowL + (rowR - rowL) / 2;

            if(target > matrix[rowMean][colR])
            {
                rowL = rowMean + 1;
            }
            else if(target < matrix[rowMean][colL])
            {
                rowR = rowMean - 1;
            }
            else {
                break;
            }
        }

        while(colL <= colR)
        {
            int colMean = colL + (colR - colL) / 2;

            if(matrix[rowMean][colMean] == target)
            {
                return true;
            }
            else if(matrix[rowMean][colMean] < target)
            {
                colL = colMean + 1;
            }
            else {
                colR = colMean - 1;
            }
        }

        return false;
    }
};
