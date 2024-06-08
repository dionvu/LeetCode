use crate::solution::Solution;

/**
* @date 2024-06-08
*/
use std::collections::HashSet;

#[allow(dead_code)]
impl Solution {
  pub fn find_disappeared_numbers(nums: Vec<i32>) -> Vec<i32> {
    let mut set = HashSet::with_capacity(nums.len());

    let mut n = nums.len() as i32;

    for num in nums.iter() {
      set.insert(*num);
      n = n.max(*num);
    }

    let mut result = Vec::with_capacity(nums.len());

    for i in 1..=n {
      if !set.contains(&i) {
        result.push(i);
      }
    }

    result
  }
}

#[test]
fn test() {}

// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
