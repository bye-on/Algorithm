const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
let isCycle = false;

rl.on('line', (line) => {
    // 입력 받는 공간
    input.push(line.trim());
}).on('close', () => {
    // 문제를 풀고 출력하는 공간
    let n = Number(input[0]);
    let cnt = Array(1000001).fill(false);
    let result = 0;

    for(let i = 0; i < n; i++) {
      let line = input[i + 1].split(' ').map(Number);
      if(!(cnt[line[0]] || cnt[line[1]] || cnt[line[2]])) 
        result++;
      cnt[line[0]] = cnt[line[1]] = cnt[line[2]] = true;
    }

    console.log(result);
});