use std::collections::HashMap;

use crate::solution::Solution;

/**
* @date 2024-05-31
*/

#[allow(dead_code)]
impl Solution {
  pub fn num_unique_emails(emails: Vec<String>) -> i32 {
    let mut map: HashMap<String, i32> = HashMap::with_capacity(emails.len());

    for email in emails.iter() {
      let split: Vec<&str> = email.split("@").collect();
      let name = split[0];
      let domain = split[1];

      let mut new_name: Vec<char> = Vec::with_capacity(name.len());
      for c in name.chars() {
        if c.is_alphabetic() {
          new_name.push(c);
        } else if c == '+' {
          break;
        } else {
          continue;
        }
      }

      let mut new_name: String = new_name.iter().collect();
      new_name += "@";
      new_name += domain;
      *map
        .entry(new_name)
        .or_insert(0) += 1;
    }
    map.len() as i32
  }
}

#[test]
fn test() {}

// https://leetcode.com/problems/unique-email-addresses/description/
