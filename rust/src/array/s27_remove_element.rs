use crate::solution::Solution;

/**
* @date 2024-06-06
*/

impl Solution {
  #[allow(dead_code)]
  pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
    let mut k = 0;

    for i in 0..nums.len() {
      if nums[i] != val {
        nums[k] = nums[i];
        k += 1;
      }
    }

    k as i32
  }
}

#[test]
fn test() {}

// https://leetcode.com/problems/remove-element/description/
