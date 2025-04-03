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
    let [n, x]  = input.shift().split(' ');
    let a = input.shift().split(' ').map(Number);
    
    let result = [];
    for(let i = 0; i < n; i++)
    {
        if(a[i] < x)
            result.push(a[i]);
    }
    
    console.log(result.join(' '));    
});