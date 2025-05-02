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
  let test_case = Number(input[0]);

  const graph = [[1, 2, 3], [4, 5, 6], [7, 8, 9], [0]];
  const dx = [-1, 1, 0, 0];
  const dy = [0, 0, -1, 1];

  let result = 0;

  let dp = Array.from({ length: 1001 }, () => Array(10).fill(1));

  const remain = 1234567;
  for (let i = 2; i < 1001; i++) {
    dp[i][0] = dp[i-1][7] % remain;
    dp[i][1] = (dp[i-1][2] + dp[i-1][4]) % remain;
    dp[i][2] = (dp[i-1][1] + dp[i-1][3] + dp[i-1][5]) % remain;
    dp[i][3] = (dp[i-1][2] + dp[i-1][6]) % remain;
    dp[i][4] = (dp[i-1][1] + dp[i-1][5] + dp[i-1][7]) % remain;
    dp[i][5] = (dp[i-1][2] + dp[i-1][4] + dp[i-1][6] + dp[i-1][8]) % remain;
    dp[i][6] = (dp[i-1][3] + dp[i-1][5] + dp[i-1][9]) % remain;
    dp[i][7] = (dp[i-1][4] + dp[i-1][8] + dp[i-1][0]) % remain;
    dp[i][8] = (dp[i-1][5] + dp[i-1][7] + dp[i-1][9]) % remain;
    dp[i][9] = (dp[i-1][6] + dp[i-1][8]) % remain;
  }

  for (let t = 0; t < test_case; t++) {
    let n = Number(input[1 + t]);

    let result = 0;
    for(let i = 0; i < 10; i++) {
      result += dp[n][i];
      result %= remain;
    }

    console.log(result);
  }
});
