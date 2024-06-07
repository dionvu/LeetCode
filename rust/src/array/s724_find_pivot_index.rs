use crate::solution::Solution;

/**
* @date 2024-06-07
*/

#[allow(dead_code)]
impl Solution {
  pub fn pivot_index(nums: Vec<i32>) -> i32 {
    let mut left_sum = 0;
    let total_sum: i32 = nums.iter().sum();

    for i in 0..nums.len() {
      let right_sum = total_sum - left_sum - nums[i];

      if right_sum == left_sum {
        return i as i32;
      }

      left_sum += nums[i];
    }

    return -1;
  }
}

#[test]
fn test() {
  assert_eq!(Solution::pivot_index(vec![1, 7, 3, 6, 5, 6]), 3);
  assert_eq!(Solution::pivot_index(vec![1, 2, 3]), -1);
}

// https://leetcode.com/problems/find-pivot-index/description/
