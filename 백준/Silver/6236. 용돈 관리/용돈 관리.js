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
  let [n, m] = input[0].split(" ").map(Number);

  let arr = [];
  let start = 1;
  let end = 0;
  for (let i = 1; i <= n; i++) {
    let num = Number(input[i]);
    arr.push(num);
    end += num;
  }

  let minnum = 0;
  while (start <= end) {
    let middle = Math.round((start + end) / 2);

    let remain = middle;
    let count = 1;
    let pass = false;
    for (let i = 0; i < n; i++) {
      if (middle < arr[i]) {
        pass = true;
        break;
      }

      if (remain < arr[i]) {
        remain = middle;
        count++;
      }
      remain -= arr[i];
    }

    if (pass || count > m) {
      start = middle + 1;
    } else {
      minnum = middle;
      end = middle - 1;
    }
  }

  console.log(minnum);
});
