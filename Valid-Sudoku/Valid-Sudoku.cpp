#include <cstdlib>
#include <iostream>
#include <cctype>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        for (size_t i = 0; i < board.size(); ++i) {
            std::unordered_set<char> row_existing_vals;
            std::unordered_set<char> col_existing_vals;

            for (size_t j = 0; j < board[i].size(); ++j) {
                char row_val = board[i][j];
                if (row_val != '.') {
                    if (row_existing_vals.find(row_val) != row_existing_vals.end()) {
                        return false;
                    }
                    row_existing_vals.emplace(row_val);
                }

                char col_val = board[j][i];
                if (col_val != '.') {
                    if (col_existing_vals.find(col_val) != col_existing_vals.end()) {
                        return false;
                    }
                    col_existing_vals.emplace(col_val);
                }
            }

            if (i % 3 == 0) {
                for (size_t col_iterate_index = 0; col_iterate_index < 3; ++col_iterate_index) {
                    std::unordered_set<char> square_existing_vals;
                    for (size_t i_iterate = 0; i_iterate < 3; ++i_iterate) {
                        for (size_t j = 0; j < 3; ++j) {
                            size_t row = i+i_iterate,
                                col = (col_iterate_index*3)+j;
                            char cell_val = board[row][col];
                            if (cell_val != '.') {
                                if (square_existing_vals.find(cell_val) != square_existing_vals.end()) {
                                    return false;
                                }
                                square_existing_vals.emplace(cell_val);
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};


int main() {
    std::vector<std::vector<char>> board{
        {'1','2','.','.','3','.','.','.','.'},
        {'4','.','.','5','.','.','.','.','.'},
        {'.','9','8','.','.','.','.','.','3'},
        {'5','.','.','.','6','.','.','.','4'},
        {'.','.','.','8','.','3','.','.','5'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','.','.','.','.','.','2','.','.'},
        {'.','.','.','4','1','9','.','.','8'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    auto result = Solution().isValidSudoku(board);
    std::cout << ((result)? "true" : "false") << std::endl;

    return EXIT_SUCCESS;
}