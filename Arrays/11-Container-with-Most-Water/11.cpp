/**
 * @date 2024 Apr 7
 */

#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int left = 0;
    int right = height.size() - 1;

    int max_area = 0;

    while (left < right) {
      const int area = min(height[left], height[right]) * (right - left);

      if (area > max_area)
        max_area = area;

      if (height[left] > height[right])
        right--;
      else
        left++;
    }

    return max_area;
  }
};
