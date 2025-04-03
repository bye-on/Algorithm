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
    let num = input[1].split(' ').map(Number);
    let x = Number(input[2]);

    num.sort((a, b) => a - b);

    let result = 0;
    let start = 0; let end = num.length - 1;
    while(start < end)
    {
        if(num[end] >= x)
            end--;
        if(num[start] >= x)
            start--;

        if((num[start] + num[end]) == x) {
            result++;
            start++; end--;
        }
        else if((num[start] + num[end]) > x) {
            end--;
        }
        else {
            start++;
        }
    }

    console.log(result);    
});