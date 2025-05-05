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
  let real = input[1].split(' ').map(Number);
  let m = Number(input[2]);
  let dream = input[3].split(' ').map(Number);
  
  const ok = (i, middle) => {
    for(let j = 0; j < n; j++) {
      if(real[j] !== dream[i + j + (middle * j)])
        return false;
    }
    return true;
  }

  let know = false;
  let minnum = 1e9; let maxnum = 0;
  let middle = m - n;
  while(middle >= 0) {
    for(let i = 0; i < m; i++) {
      if(ok(i, middle)) {
        maxnum = Math.max(maxnum, middle);
        minnum = Math.min(minnum, middle);
        know = true;
      }
    }

    middle--;
  }

  if(know)
    console.log(`${minnum} ${maxnum}`);
  else
    console.log(-1);
});
