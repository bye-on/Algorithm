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
  let t = Number(input[0]);
  let ans = [];
  for (let i = 0; i < t; i++) {
    let n = Number(input[1 + 2 * i]);
    let arr = input[2 + 2 * i].split(" ").map(Number);

    let max = arr[n - 1];
    let result = 0;
    for (let j = n - 1; j >= 0; j--) {
      if (max < arr[j]) max = arr[j];
      else {
        result += max - arr[j];
      }
    }
    ans.push(result);
  }

  console.log(ans.join('\n'));
});
