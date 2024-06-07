use crate::solution::Solution;

/**
* @date
*/

#[allow(dead_code)]
impl Solution {
  pub fn largest_number(mut nums: Vec<i32>) -> String {
    // Sort the numbers using custom comparison function
    nums.sort_by(|&a, &b| {
      let ab = format!("{}{}", a, b);
      let ba = format!("{}{}", b, a);
      ba.cmp(&ab)
    });

    // Collect the sorted numbers into a single string
    let result: String = nums
      .iter()
      .map(|&i| i.to_string())
      .collect();

    // Remove leading zeros and handle the case where the result is empty
    let result = result
      .trim_start_matches('0')
      .to_string();

    if result.is_empty() {
      "0".to_string()
    } else {
      result
    }
  }
}

#[test]
fn test() {}

// https://leetcode.com/problems/largest-number/description/
