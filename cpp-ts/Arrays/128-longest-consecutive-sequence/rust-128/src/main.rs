struct Solution {}
fn main() {
  println!(
    "{}",
    Solution::longest_consecutive(vec![1, 5, 3, 2, 6, 7, 10])
  );
}

impl Solution {
  pub fn longest_consecutive(nums: Vec<i32>) -> i32 {
    if nums.is_empty() {
      return 0;
    }
    let mut nums = nums;
    nums.sort();

    let mut longest_seq: i32 = 1;
    let mut streak = 1;

    for i in 1..nums.len() {
      if nums[i] == nums[i - 1] {
        continue;
      }
      if nums[i] == nums[i - 1] + 1 {
        streak += 1;
      } else {
        longest_seq = longest_seq.max(streak);
        streak = 1;
      }
    }

    return longest_seq.max(streak);
  }
}
