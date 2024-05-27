/**
* @date 05/25/2024
*/
use crate::solution::Solution;

#[allow(dead_code)]
impl Solution {
  pub fn is_anagram(s: String, t: String) -> bool {
    let mut s: Vec<char> = s.chars().collect();
    s.sort();

    let mut t: Vec<char> = t.chars().collect();
    t.sort();

    if s.len() != t.len() {
      return false;
    }

    for i in 0..s.len() {
      if s[i] != t[i] {
        return false;
      }
    }

    true
  }
}

#[test]
fn test() {
  assert_eq!(
    Solution::is_anagram("racecar".to_string(), "acreacr".to_string(),).to_string(),
    "true"
  )
}

// https://leetcode.com/problems/contains-duplicate/submissions/1268758946/
