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
    let a = Number(input[0]);
    let b = Number(input[1]);
    let c = Number(input[2]);

    let result = (a*b*c).toString();
    let num = Array(10).fill(0);
    for(let i = 0; i < result.length; i++)
    {
        let n = Number(result[i]);
        num[n]++;
    }

    for(let i = 0; i < num.length; i++)
    {
        console.log(num[i]);
    }
});