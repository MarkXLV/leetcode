#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Use bitmasks to track seen digits in rows, columns, and 3x3 boxes.
        // rows[r] bit d means digit (d+1) has appeared in row r.
        int rows[9] = {0};
        int cols[9] = {0};
        int boxes[9] = {0};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                char ch = board[r][c];
                if (ch == '.') continue; // Ignore empty cells

                int digit = ch - '1';      // Map '1'..'9' -> 0..8
                int mask = 1 << digit;
                int boxIndex = (r / 3) * 3 + (c / 3);

                // If digit already exists in row, column, or box => invalid
                if ((rows[r] & mask) || (cols[c] & mask) || (boxes[boxIndex] & mask)) {
                    return false;
                }

                // Mark digit as seen
                rows[r] |= mask;
                cols[c] |= mask;
                boxes[boxIndex] |= mask;
            }
        }

        return true; // No conflicts found
    }
};