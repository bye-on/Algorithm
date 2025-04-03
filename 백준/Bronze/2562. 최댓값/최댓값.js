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
    let a = input.map((value, index) => [Number(value), index]);
    a.sort((x, y) => {
        if(x[0] == y[0])
            return x[1] - y[1];
        return y[0] - x[0];
    })
    console.log(a[0][0]);
    console.log(a[0][1] + 1);
});