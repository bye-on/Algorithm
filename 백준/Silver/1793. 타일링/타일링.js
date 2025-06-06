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
  let n = Math.max(...input);
  let dp = Array(n + 1).fill(1n);
  dp[1] = 1n;
  dp[2] = 3n;

  for (let i = 3; i < 251; i++) {
    dp[i] = dp[i - 2] * 2n + dp[i - 1];
  }

  for (const m of input) {
    console.log(dp[m].toString());
  }

  process.exit(0);
});
