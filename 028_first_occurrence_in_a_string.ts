/**
  * @brief Goes through the string haystack and checking each substring with length of needle.
  *
  * @returns Index of the needle substring found, else -1.
  */
function strStr(haystack: string, needle: string): number {
  const needleLen = needle.length;
  const haystackLen = haystack.length;

  if (needleLen > haystackLen) return -1; // Needle can't fit in haystack
  if (needleLen === haystackLen && needle !== haystack) return -1; // Needle is the exact size but isn't equal
  if (needle === haystack) return 0; // Exact size and equal

  for (let i = 0; i <= haystackLen - needleLen; i++)
    if (haystack.substring(i, i + needleLen) === needle) return i;

  return -1;
}

// Complexitity O(m - n) Where m is the length of haystack, and n is the length of needle
// Space is Unknown as needle & haystack size is not known
