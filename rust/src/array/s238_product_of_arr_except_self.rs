use crate::solution::Solution;

/**
* @date 2024-05-29
*/

#[allow(dead_code)]
impl Solution {
  pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
    let mut left_product = 1;
    let mut right_product = 1;
    let mut ans = vec![1; nums.len()];

    for (idx, num) in nums.iter().enumerate() {
      ans[idx] *= left_product;
      left_product *= *num;
    }

    for (idx, num) in nums.iter().enumerate().rev() {
      ans[idx] *= right_product;
      right_product *= *num;
    }

    ans
  }
}

#[test]
fn test() {}

// https://leetcode.com/problems/product-of-array-except-self/
