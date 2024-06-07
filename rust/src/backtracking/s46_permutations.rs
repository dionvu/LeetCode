use crate::solution::Solution;

/**
* @date 2024-05-29
*/

#[allow(dead_code)]
impl Solution {
  pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
    let mut result = Vec::with_capacity((1..=nums.len()).product());

    Self::backtrack(nums, vec![], &mut result);

    result
  }

  fn backtrack(available_nums: Vec<i32>, path: Vec<i32>, result: &mut Vec<Vec<i32>>) {
    if available_nums.is_empty() {
      result.push(path);
      return;
    }

    for i in 0..available_nums.len() {
      let mut new_nums = available_nums.clone();
      new_nums.remove(i);
      let mut new_path = path.clone();
      new_path.push(available_nums[i]);

      Self::backtrack(new_nums, new_path, result);
    }
  }
}

#[test]
fn test() {}

// https://leetcode.com/problems/permutations/
