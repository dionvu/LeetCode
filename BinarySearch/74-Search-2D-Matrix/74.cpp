/**
 * @date 2024 Apr 20
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

      if (target < lower)
        return false;

      if (lower <= target && target <= upper)
        return binary_search(matrix[i].begin(), matrix[i].end(), target);
    }

    return false;
  }
};
