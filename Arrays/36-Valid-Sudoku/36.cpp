/**
 * @brief I really love for loopz.
 * @date 2024 Apr 2
 *
 * Approach:
 * Brute force rows, cols, and then boxes using multiple maps.
 *
 * Time:
 * O(N^2 + N^2 + (N/3)^2)
 * O(N^2)
 */

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool isValidSudoku(vector<vector<char>> &board) {
    for (int row = 0; row < board.size(); row++) {

      unordered_map<char, bool> rowMap;

      for (int col = 0; col < board[0].size(); col++) {
        if (rowMap[board[row][col]])
          return false;
        else if (board[row][col] != '.')
          rowMap[board[row][col]] = true;
      }
    }

    for (int col = 0; col < board.size(); col++) {

      unordered_map<char, bool> colMap;

      for (int row = 0; row < board.size(); row++) {
        if (colMap[board[row][col]])
          return false;
        else if (board[row][col] != '.')
          colMap[board[row][col]] = true;
      }
    }

    for (int row = 0; row < board.size(); row += 3) {
      for (int col = 0; col < board.size(); col += 3) {

        unordered_map<char, bool> boxMap;

        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
            if (boxMap[board[row + i][col + j]])
              return false;
            else if (board[row + i][col + j] != '.')
              boxMap[board[row + i][col + j]] = true;
          }
        }
      }
    }

    return true;
  }
};
