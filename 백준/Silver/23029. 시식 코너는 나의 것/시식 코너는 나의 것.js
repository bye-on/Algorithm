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
  let n = Number(input[0]);
  let arr = [];
  for(let i = 1; i <= n; i++) {
    arr.push(Number(input[i]))
  }
  let dp = Array.from({length : n + 1}, () => Array(3).fill(0));

  dp[0][0] = 0; // 현재 위치 안 먹음
  dp[0][1] = arr[0]; // 현재 위치 먹음 (연속 X)
  dp[0][2] = 0; // 두번 연속 먹음 (0번째는 두번 연속 X)

  for(let i = 1; i < n; i++) {
    dp[i][0] = Math.max(...dp[i-1]);
    dp[i][1] = dp[i-1][0] + arr[i];
    dp[i][2] = dp[i-1][1] + Math.floor(arr[i] / 2);
  }

  console.log(Math.max(...dp[n - 1]));
});
