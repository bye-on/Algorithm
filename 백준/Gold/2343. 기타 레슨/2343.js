const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
let input = [];
rl.on("line", function (line) {
  input.push(line);
}).on("close", function () {
  //입력을 받은 뒤 실행할 코드
  let [N, M] = input[0].split(" ").map(Number);
  let arr = input[1].split(" ").map(Number);

  let sum = arr.reduce((a, b) => a + b, 0);

  let start = 1;
  let end = sum;
  let result = sum;
  while (start <= end) {
    let cnt = 0;
    let middle = Math.round((start + end) / 2);
    let calc = Array(M).fill(0);
    for (let i = 0; i < N; i) {
      if (cnt == M) {
        break;
      }

      if (calc[cnt] + arr[i] <= middle) calc[cnt] += arr[i++];
      else cnt++;
    }

    let calcSum = calc.reduce((a, b) => a + b, 0);

    if (calcSum < sum) {
      start = middle + 1;
    } else {
      result = middle;
      end = middle - 1;
    }
  }

  console.log(result);
  process.exit(); //종료문
});
