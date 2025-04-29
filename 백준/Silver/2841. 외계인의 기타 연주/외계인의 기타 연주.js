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
  let [n, p] = input[0].split(" ").map(Number);

  let result = 0;
  let stack = Array.from({ length: n + 1 }, () => []);

  for (let i = 0; i < n; i++) {
    let [N, P] = input[1 + i].split(" ").map(Number);
    if (stack[N].length === 0) {
      stack[N].push(P);
      result++;
    } else {
      while(stack[N][stack[N].length - 1] > P) {
        stack[N].pop();
        result++;
      }
      if(stack[N][stack[N].length - 1] !== P) {
        stack[N].push(P);
        result++;
      }
    }
  }

  console.log(result);
});
