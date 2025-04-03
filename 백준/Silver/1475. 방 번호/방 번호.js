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
    let n = input[0];
    let num = Array(10).fill(0);
    for(let i = 0; i < n.length; i++)
    {
        let a = Number(n[i]);
        if(a == 9 || a == 6) {
            if(num[6] > num[9])
                num[9]++;
            else if(num[9] > num[6])
                num[6]++;
            else
                num[a]++;
        }
        else
            num[a]++;
    }

    let m = 0;
    for(let i = 0; i < 10; i++)
        m = Math.max(m, num[i]);

    console.log(m);    
});