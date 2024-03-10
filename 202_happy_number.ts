/**
 * Determines if a number is a happy number. Detecting unhappy numbers by checking
 * if the current sum was already visited (loop).
 * @date 2024 March 10
 */

function isHappy(n: number): boolean {
  let string: string[];
  let sum: number;
  let stack: number[] = [];
  while (n !== 1) {
    string = n.toString().split('');
    sum = 0;
    for (let i = 0; i < string.length; i++) {
      sum += Math.pow(parseInt(string[i]), 2);
    }
    if (
      stack.find(target => target === sum)
    ) return false;
    stack.push(sum);
    n = sum;
  }
  return true;
}
