function longestSubstr(str: string): number {
  let map: { [key: string]: number } = {}; // Key map, key is to hold the chars in str, value is a number the index

  let front = 0, back = 0, longestLength = 0; // Back = The last char in the sequence, front = leading char, length = length of sequence

  for (; front < str.length; front++) {
    if (map[str[front]] !== undefined) { // If the map does contain the letter
      back = Math.max(back, (map[str[front]] + 1)); // If the repeat letter index + 1 is more than back then back is now the index + 1.
      // Else the repeat letter is at back.
    }

    map[str[front]] = front;
    longestLength = Math.max(longestLength, front - back + 1);
  }
  return longestLength;
}

console.log(longestSubstr('bacdgbbabcabc'));
console.log(longestSubstr('abcaa'));
