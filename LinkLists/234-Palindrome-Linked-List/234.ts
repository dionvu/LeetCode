/**
 * @date 2024 March 22
 * Time: O(N)
 * Space: O(N)
 */

class ListNode {
  val: number
  next: ListNode | null
  constructor(val?: number, next?: ListNode | null) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
  }
}

function isPalindrome(head: ListNode | null): boolean {
  const values: number[] = [];

  while (head) {
    values.push(head.val);
    head = head.next;
  }

  return values.join() === values.reverse().join();
};
