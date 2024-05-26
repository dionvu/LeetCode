/**
 * @date 2024 Apr 20
 *
 * Approach: Decide which row of the matrix to search by seeing if target fits
 * in the upper and lower bound of each row. binary_search used to find if
 * target exists.
 *
 * Time:
 * n = rows
 * m = cols
 * Check every row bounds onces O(n)
 * Search through row in O(log(m)) time.
 * O(n + log(m))
 *
 * Space:
 *
 *
 * My difficulty: 4
 * Constant space rows and cols.
 * 2 integers for each row.
 * O(2N)
 * O(N)
 */

#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {

    const int rows = matrix.size();
    const int cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {

      const int lower = matrix[i][0];
      const int upper = matrix[i][cols - 1];

      // Target was supposed to be in-between the prev upper bound and curr
      // lower bound.
      if (target < lower)
        return false;

      // Target is in our row bounds.
      if (lower <= target && target <= upper)
        return binary_search(matrix[i].begin(), matrix[i].end(), target);
    }

    return false;
  }
};
