/**
 * Uses an array to track values that have already appeared.
 * @date 2024 March 8
 */

class ListNode {
  val: number
  next: ListNode | null
  constructor(val?: number, next?: ListNode | null) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
  }
};

function deleteDuplicates(head: ListNode | null): ListNode | null {
  if (head === null) return null; // Is head null
  if (head.next === null) return head; // Is head the only Node

  let last: ListNode = head;
  let cur: ListNode | null = head.next;

  let stack: number[] = [];

  while (cur) {
    // Check if cur value is already on stack
    if (stack.find(node => node === cur!.val) !== undefined) {
      if (cur.next === null) {
        // remove 1
        last.next = null;
        cur = null;
      }
      else {
        last.next = cur.next;
        cur = cur!.next;
      }
    }
    // Cur val is not on stack
    else {
      stack.push(cur.val);
      last = cur;
      cur = cur.next;
    }
  }
  return head;
};
