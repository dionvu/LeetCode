/**
 * @date 2024 Apr 2
 *
 * Approach:
 * Caculating the left products of each number, then looping backwards to
 * calculate the right products and multiply with the already calculated left
 * products.
 *
 * Time:
 * = O(N + N + N)
 * = O(3N)
 * O(N)
 *
 * Comparitively this is quite slow to other solutions because of filling the
 * vector.
 */

#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> products;

    // Initializes N spaces to 1
    for (int i = 0; i < nums.size(); i++)
      products.push_back(1);

    // Assigns the left products except self then adds self to the left product.
    int leftProduct = 1;
    for (int i = 0; i < nums.size(); i++) {
      products[i] = leftProduct;
      leftProduct *= nums[i];
    }

    // Assigns the right products except self then adds self to the right
    // product. Multiplies right product with the already produced left
    // products.
    int rightProduct = 1;
    for (int i = nums.size() - 1; i >= 0; i--) {
      products[i] *= rightProduct;
      rightProduct *= nums[i];
    }

    return products;
  }
};
