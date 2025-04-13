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
    let [x, y] = input[0].split(' ').map(Number);
    let t = y - x;
    let cnt = 0; let i = 1; 
    while(t > 0) {
      t -= i;
      cnt++;
      if(t > 0) {
        t -= i;
        cnt++;
        i++;
      }
    }

    console.log(cnt);
});