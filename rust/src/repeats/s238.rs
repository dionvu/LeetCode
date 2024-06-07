use crate::solution::Solution;

#[allow(dead_code)]
impl Solution {
  pub fn product_except_self_repeat(nums: Vec<i32>) -> Vec<i32> {
    let mut products = vec![1; nums.len()];

    let mut left = 1;
    let mut right = 1;

    for i in 0..nums.len() {
      products[i] *= left;
      left *= nums[i];
    }

    for i in (0..nums.len()).rev() {
      products[i] *= right;
      right *= nums[i];
    }

    products
  }
}

#[test]
fn test() {}
