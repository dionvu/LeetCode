use std::collections::HashSet;

use crate::solution::Solution;

/**
* @date 2024-05-27
*/

#[allow(dead_code)]
impl Solution {
  pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
    let nums: HashSet<i32> = nums.into_iter().collect();
    let mut longest_streak = 0;

    for num in nums.iter() {
      if !nums.contains(&(*num - 1)) {
        let mut curr_num = *num;
        let mut curr_streak = 1;

        while nums.contains(&(curr_num + 1)) {
          curr_num += 1;
          curr_streak += 1;
        }

        longest_streak = curr_streak.max(longest_streak);
      }
    }

    longest_streak
  }
}

#[test]
fn test() {}

// https://leetcode.com/problems/longest-consecutive-sequence/
