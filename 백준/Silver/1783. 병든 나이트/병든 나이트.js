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
  let [n, m] = input.shift().split(" ").map(Number);

  let answer = 0;
  if (n >= 3) {
    if (m <= 4) {
      answer = m;
    } else if (m < 7) {
      answer = 4;
    } else {
      answer = m - 2;
    }
  } else if (n == 2) {
    if (m < 3) {
      answer = 1;
    } else if (m < 5) {
      answer = 2;
    } else if (m < 7) {
      answer = 3;
    } else {
      answer = 4;
    }
  } else answer = 1;

  console.log(answer);
  process.exit(0);
});
