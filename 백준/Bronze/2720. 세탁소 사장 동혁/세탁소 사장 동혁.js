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
  let arr = [0.25, 0.1, 0.05, 0.01];
  let n = Number(input[0]);

  for (let i = 0; i < n; i++) {
    let m = Number(input[i + 1] / 100);

    let result = [];
    for (let i = 0; i < arr.length; i++) {
      result.push(Math.floor(m / arr[i]));
      m %= arr[i];
      m = Number(m.toFixed(2));
    }

    console.log(result.join(" "));
  }
});
