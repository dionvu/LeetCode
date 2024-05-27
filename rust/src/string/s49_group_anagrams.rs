use crate::solution::Solution;
use std::collections::HashMap;

/**
* @date 2024-05-27
*/

#[allow(dead_code)]
impl Solution {
  pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
    let mut groups: HashMap<String, Vec<String>> = HashMap::with_capacity(strs.len());

    for str in strs.iter() {
      let sorted_str: String = {
        let mut chars: Vec<char> = str.chars().collect();
        chars.sort();
        chars.iter().collect()
      };

      groups
        .entry(sorted_str)
        .or_default()
        .push(str.clone());
    }

    // groups
    //   .values()
    //   .cloned()
    //   .collect()

    groups.into_values().collect()
  }
}

#[test]
fn test() {}

// https://leetcode.com/problems/group-anagrams/
