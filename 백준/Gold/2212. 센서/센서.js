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
    let m = Number(input[1]);
    let arr = input[2].split(' ').map(Number);

    arr.sort((a, b) => a - b);
    
    let d = [];
    for(let i = 1; i < n; i++) {
      d.push(arr[i] - arr[i-1]);
    }

    d.sort((a, b) => a - b);
    for(let i = 0; i < m - 1; i++) {
      if(d.length > 0) d.pop();
    }
    
    let result = 0;
    for(let i = 0; i < d.length; i++) {
      result += d[i];
    }
    console.log(result);
});