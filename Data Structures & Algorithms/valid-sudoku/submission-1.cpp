class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<std::unordered_set<char>> verticalRows;
        verticalRows.resize(9);
        std::vector<std::unordered_set<char>> horizontalRows;
        horizontalRows.resize(9);
        std::vector<std::unordered_set<char>> boxes;
        boxes.resize(9);

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
                if(verticalRows[i].contains(c) or horizontalRows[j].contains(c) or boxes[boxIndex].contains(c))
                {
                    return false;
                }

                verticalRows[i].insert(c);
                horizontalRows[j].insert(c);
                boxes[boxIndex].insert(c);
            }
        }

        return true;
    }
};
