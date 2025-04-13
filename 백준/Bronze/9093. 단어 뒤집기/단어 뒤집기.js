const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];

rl.on('line', (line) => {
    // 입력 받는 공간
    input.push(line.trim());
}).on('close', () => {
    // 문제를 풀고 출력하는 공간
    let n = Number(input[0]);

    for(let i = 1; i <= n; i++) {
      let str = input[i].split(' ');
      let l = [];
      for(let j = 0; j < str.length; j++) {
        l.push(str[j].split('').reverse().join(''));
      }
      console.log(l.join(' '));
    }
});