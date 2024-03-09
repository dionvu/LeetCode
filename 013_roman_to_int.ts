function romanToInt(s: string): number {
  const numerals = {
    'I': 1,
    'V': 5,
    'X': 10,
    'L': 50,
    'C': 100,
    'D': 500,
    'M': 1000,
  }

  let ints = s.split('').map(c => numerals[c]);

  return ints.reduce((acc, x, i) => x < ints[i + 1] ? acc - x : acc + x, 0);
}

alert(romanToInt('XXVIIMLM'));
