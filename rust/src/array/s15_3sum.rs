use crate::solution::Solution;

/**
* @date 2024-05-29
*/

impl Solution {
  #[allow(dead_code)]
  pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
    let mut result: Vec<Vec<i32>> = Vec::new();

    let mut nums = nums;
    nums.sort();

    let mut start: usize;
    let mut end: usize;
    for i in 0..nums.len() {
      if i > 0 && nums[i] == nums[i - 1] {
        continue;
      }

      start = i + 1;
      end = nums.len() - 1;

      while start < end {
        let target = -nums[i];
        let sum = dbg!(nums[start] + nums[end]);

        if target == sum {
          result.push(vec![nums[i], nums[start], nums[end]]);

          while start < end && nums[start + 1] == nums[start] {
            start += 1;
          }

          while end > start && nums[end] == nums[end - 1] {
            end -= 1;
          }

          start += 1;
          end -= 1;
        } else if sum > target {
          end -= 1;
        } else {
          start += 1;
        }
      }
    }

    result
  }
}

#[test]
fn test_three_sum() {
  let nums = vec![-1, 0, 1, 2, -1, -4];
  let result = Solution::three_sum(nums);
  assert_eq!(result, vec![vec![-1, -1, 2], vec![-1, 0, 1]]);
}

// https://leetcode.com/problems/3sum/
//
// -4, -1, -1, 0, 1, 2
//
// -4, 2 (2 exist ? No, if more than 0 move bigger, else move smaller)
// -1 2 (-1 exist? check index != )
