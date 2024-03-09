/**
 * Uses a dummy head and a ptr to merge two lists in sorted order.
 * @date 2024 March 9
 */

class ListNode {
  val: number
  next: ListNode | null
  constructor(val?: number, next?: ListNode | null) {
    this.val = (val === undefined ? 0 : val)
    this.next = (next === undefined ? null : next)
  }
};

function mergeTwoLists(list1: ListNode | null, list2: ListNode | null): ListNode | null {
  let dummyHead: ListNode = new ListNode; // The return head is the value after.
  let cur = dummyHead; // Pointer to the current list node

  // If both, or one of the lists is null
  if (!list1)
    return list2;
  else if (!list2)
    return list1;

  // While both pointers are still pointing at a list node
  while (list1 && list2) {
    // Values equal
    if (list1.val == list2.val) {
      // Smallest doesn't matter

      // Adds list1 to the current place
      cur.next = list1;
      cur = list1;
      list1 = list1.next;

      // Adds list2 to the current place
      cur.next = list2;
      cur = list2;
      list2 = list2.next;
    }
    // list1 value greater
    // list1 stays and list2 moves
    else if (list1.val > list2.val) {
      cur.next = list2;
      cur = list2;
      list2 = list2.next;
    }
    // list2 value is greater
    // list2 stays and list1 moves
    else {
      cur.next = list1;
      cur = list1;
      list1 = list1.next;
    }
  }

  // Once one list is null, appends the rest of other list onto the return
  if (!list1)
    cur.next = list2;
  else if (!list2)
    cur.next = list1;

  return dummyHead.next;
};
