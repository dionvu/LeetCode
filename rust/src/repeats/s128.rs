use crate::solution::Solution;

use std::collections::HashMap;

/**
* @date 2024-06-03
*/

#[allow(dead_code)]
impl Solution {
  pub fn longest_consecutive_repeat(nums: Vec<i32>) -> i32 {
    let mut map = HashMap::with_capacity(nums.len());

    for i in 0..nums.len() {
      map.insert(nums[i], i);
    }

    let mut longest_streak = 0;
    let mut streak;

    let mut curr: i32;
    for (key, _) in map.iter() {
      streak = 0;

      if map.contains_key(&(*key - 1)) {
        continue;
      }

      curr = *key;
      streak += 1;
      while map.contains_key(&(curr + 1)) {
        streak += 1;
        curr += 1;
        longest_streak = longest_streak.max(streak);
      }
      longest_streak = longest_streak.max(streak);
    }

    longest_streak
  }
}

#[test]
fn test() {}

// https://leetcode.com/problems/longest-consecutive-sequence/
