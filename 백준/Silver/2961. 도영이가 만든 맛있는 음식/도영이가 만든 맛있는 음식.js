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
  let n = Number(input.shift());
  let sour = [];
  let sweet = [];

  for (let i = 0; i < n; i++) {
    let [x, y] = input.shift().split(" ").map(Number);
    sour.push(x);
    sweet.push(y);
  }

  let answer = Infinity;
  const combination = (sourTmp, sweetTmp, depth) => {
    if (depth === n) return;
    combination(sourTmp, sweetTmp, depth + 1);
    sourTmp *= sour[depth];
    sweetTmp += sweet[depth];

    let result = Math.abs(sourTmp - sweetTmp);
    answer = Math.min(result, answer);
    combination(sourTmp, sweetTmp, depth + 1);
  };

  let sourTmp = 1;
  let sweetTmp = 0;
  combination(sourTmp, sweetTmp, 0);
  console.log(answer);

  process.exit(0);
});
