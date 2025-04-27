const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
let isCycle = false;

rl.on("line", (line) => {
  // 입력 받는 공간
  input.push(line.trim());
}).on("close", () => {
  // 문제를 풀고 출력하는 공간
  let n = Number(input[0]);
  let p = input[1].split(' ').map(Number);
  p.unshift(0);

  let dp = Array(n + 1).fill(1e9);
  dp[0] = 0;
  dp[1] = p[1];
  for(let i = 1; i <= n; i++) {
    for(let j = 1; j <= i; j++) {
      dp[i] = Math.min(dp[i], dp[i - j] + p[j]);
    }
  }

  console.log(dp[n]);
});
