const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
rl.on("line", (line) => {
  // 입력 받는 공간
  input.push(line.trim());
}).on("close", () => {
  // 문제를 풀고 출력하는 공간
  let arr = [5 * 60, 60, 10];
  let n = Number(input[0]);
  let result = [];
  for (let i = 0; i < 3; i++) {
    result.push(Math.floor(n / arr[i]));
    n %= arr[i];
  }

  if (n !== 0) console.log(-1);
  else console.log(result.join(" "));
});
