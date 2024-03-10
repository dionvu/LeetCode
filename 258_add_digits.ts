/**
 * Loops until the sum of num's digits is single digit.
 * @date 2024 March 10
 */

function addDigits(num: number): number {
  let sum: number;

  do {
    sum = 0;
    num.toString().split('')
      .forEach((x) => sum += parseInt(x));
    num = sum;
  } while (sum.toString().length !== 1 && sum !== 0);

  return sum;
};

alert(addDigits(39));
alert(addDigits(0));
