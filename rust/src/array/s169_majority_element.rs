use crate::solution::Solution;

/**
* @date 2024-06-07
*/
use std::collections::HashMap;

#[allow(dead_code)]
impl Solution {
  pub fn majority_element(nums: Vec<i32>) -> i32 {
    let mut map = HashMap::with_capacity(nums.len());

    for num in nums.iter() {
      let count = map.entry(*num).or_insert(0);
      *count += 1;

      if *count > nums.len() as i32 / 2 {
        return *num;
      }
    }

    unreachable!()
  }
}

#[test]
fn test() {}

// https://leetcode.com/problems/majority-element/description/
