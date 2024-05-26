/**
* @date 2024-05-25
*/
use std::collections::HashMap;

use crate::solution::Solution;

#[allow(dead_code)]
impl Solution {
  pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut map: HashMap<i32, i32> = HashMap::with_capacity(nums.len());

    for (idx, num) in nums.iter().enumerate() {
      if !map.contains_key(num) {
        map.insert(*num, idx as i32);
      }
      if map.contains_key(&(target - *num)) && map.get(&(target - *num)) != map.get(num) {
        return vec![
          *map
            .get(&(target - *num))
            .unwrap(),
          *map.get(num).unwrap(),
        ];
      }
    }

    vec![]
  }
}

#[test]
fn test() {}
