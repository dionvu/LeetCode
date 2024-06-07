use crate::solution::Solution;

use std::collections::HashMap;

/**
* @date 2024-06-01
*/

#[allow(dead_code)]
impl Solution {
  pub fn dest_city(paths: Vec<Vec<String>>) -> String {
    let mut map = HashMap::with_capacity(paths.len());

    for path in paths.iter() {
      map.insert(path[0].clone(), path[1].clone());
    }

    for city in map.values() {
      if !map.contains_key(city) {
        return city.clone();
      }
    }

    "".to_string()
  }
}

#[test]
fn test() {}

// https://leetcode.com/problems/destination-city/description/
