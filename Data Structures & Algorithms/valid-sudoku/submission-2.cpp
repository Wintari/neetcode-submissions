class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int boxes[9]{0};
        int rows[9]{0};
        int cols[9]{0};

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char c = board[i][j];
                if(c == '.')
                {
                    continue;
                }

                if(c < '1' or c > '9')
                {
                    return false;
                }

                size_t boxIndex = (j / 3) * 3 + i / 3;
                int bitMask = 1 << (c - '1');
                if((rows[i] & bitMask) or (cols[j] & bitMask) or (boxes[boxIndex] & bitMask))
                {
                    return false;
                }

                rows[i] |= bitMask;
                cols[j] |= bitMask;
                boxes[boxIndex] |= bitMask;
            }   
        }

        return true;
    }
};
