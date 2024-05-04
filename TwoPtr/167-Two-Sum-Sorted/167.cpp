#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {

    int left = 0;
    int right = numbers.size() - 1;

    vector<int> pair;

    while (left < right) {

      const int sum = numbers[left] + numbers[right];

      if (sum == target) {
        pair.push_back(left + 1);
        pair.push_back(right + 1);
        return pair;
      }

      else if (sum > target)
        if (numbers[left] > numbers[right])
          left++;
        else
          right--;

      else if (numbers[left] > numbers[right])
        right--;
      else
        left++;
    }

    return pair;
  }
};
