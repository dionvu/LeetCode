function isPalindrome(x: number): boolean {
  if (x < 0) return false; // -121 is not 121-

  // Converts x to string, splits every character, and reverses into an array of string
  let reverse: string[] = x.toString().split('').reverse();

  // Checks if the string at i is not equal to string x at i
  for (let i = 0; i < reverse.length; i++)
    if (reverse[i] !== x.toString()[i]) return false;

  return true;
};

alert(isPalindrome(112211));
