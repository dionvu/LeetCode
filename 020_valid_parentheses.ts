function isValid(s: string): boolean {
  // Maps the closing bracket to correct opening bracket.
  const map = {
    ')': '(',
    ']': '[',
    '}': '{',
  }

  // If the string is odd length.
  if (s.length % 2 !== 0) return false;

  // Checks if the first bracket is a closing.
  // If map bracket exists then it is closing, else starts with opening.
  if (map[s[0], 0] !== undefined) return false;

  let stack: string[] = [];
  let index = 0;

  for (const char of s) {
    // The current character is an ending bracket
    if (map[char]) {
      // False if no ending bracket as the newest element on the stack.
      if (stack[index - 1] !== map[char]) return false;

      // Else it is valid closing, and we pop the last element.
      else {
        stack.pop();
        index--;
      }
    }

    // The current character is an opening bracket.
    else {
      stack.push(char);
      index++;
    }
  }

  // If the stack still has opening brackets on it.
  return stack.length === 0;
};

console.log(isValid('([{}])'));
console.log(isValid('()[]{}'));
console.log(isValid('{)'));
console.log(isValid('('));
console.log(isValid('([}}])'))
