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
    let a = input[0];
    let b = input[1];

    let alphaA = Array(26).fill(0);
    let alphaB = Array(26).fill(0);

    for(let i = 0; i < a.length; i++)
    {
        let num = a.charCodeAt(i) - 97;
        alphaA[num]++;        
    }

    for(let i = 0; i < b.length; i++)
    {
        let num = b.charCodeAt(i) - 97;
        alphaB[num]++;        
    }
    
    let result = 0;
    for(let i = 0; i < 26; i++)
    {
        let tmp = Math.abs(alphaA[i] - alphaB[i]);
        result += tmp;
    }

    console.log(result);
});