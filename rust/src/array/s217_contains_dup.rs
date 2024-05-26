use crate::solution::Solution;
use std::collections::HashSet;

/**
* @date 2024-05-26
*/

#[allow(dead_code)]
impl Solution {
  pub fn contains_duplicate(nums: Vec<i32>) -> bool {
    let mut map: HashSet<i32> = HashSet::with_capacity(nums.len());

    for num in nums.iter() {
      if map.contains(num) {
        return true;
      } else {
        map.insert(*num);
      }
    }

    false
  }
}

#[test]
fn test() {
  assert_eq!(Solution::contains_duplicate(vec![]).to_string(), "false");
  assert_eq!(
    Solution::contains_duplicate(vec![1, 2, 3, 1]).to_string(),
    "true"
  );
  assert_eq!(
    Solution::contains_duplicate(vec![1, 2, 0, 9]).to_string(),
    "false"
  );
}
