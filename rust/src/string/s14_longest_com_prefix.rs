/**
* @date 2024-05-25
*/
use crate::solution::Solution;

#[allow(dead_code)]
impl Solution {
  pub fn longest_common_prefix(strs: Vec<String>) -> String {
    let mut strs = strs;
    strs.sort();

    if strs.is_empty() {
      return "".to_string();
    }

    let first: Vec<char> = strs[0].chars().collect();
    let second: Vec<char> = strs[strs.len()]
      .chars()
      .collect();

    let mut ans: Vec<char> = vec![];
    for i in 0..first.len().min(second.len()) {
      if first[i] == second[i] {
        ans.push(first[i]);
      } else {
        return ans.iter().collect();
      }
    }

    ans.iter().collect()
  }
}
