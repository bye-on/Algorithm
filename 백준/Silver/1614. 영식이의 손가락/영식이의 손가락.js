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
    let m = Number(input[1]);

    let cnt = 0;
    if(n === 1) {
        if(m > 0)
            cnt += (m * 8);
    }
    else if(n === 2) {
        cnt += 1;

        for(let i = 1; i <= m; i++) {
            if(i % 2 === 0) {
                cnt += 2;
            }
            else {
                cnt += 6;
            }
        }
    }
    else if(n === 3) {
        cnt += 2;
        if(m > 0)
            cnt += (m * 4);
    }
    else if(n === 4) {
        cnt += 3;

        for(let i = 0; i < m; i++) {
            if(i % 2 === 0) {
                cnt += 2;
            }
            else {
                cnt += 6;
            }
        }
    }
    else if(n === 5) {
        cnt += 4;
        if(m > 0)
            cnt += (m * 8);
    }

    console.log(cnt);
});