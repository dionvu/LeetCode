#include <vector>

class Solution {
public:
  std::vector<int> productExceptSelf(std::vector<int> &nums) {

    const int size = nums.size();

    std::vector<int> products(size, 1);

    int product_left = 1;

    for (int i = 0; i < size; i++) {
      products[i] = product_left;
      product_left *= nums[i];
    }

    int product_right = 1;

    for (int i = size - 1; i >= 0; i--) {
      products[i] *= product_right;
      product_right *= nums[i];
    }

    return products;
  }
};
