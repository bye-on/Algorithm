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
    let n = input.shift().split(' ').map(Number);
    let num1 = input.shift().split(' ').map(Number);
   
    let m = input.shift().split(' ').map(Number);
    let num2 = input.shift().split(' ').map(Number);
    
    num1.sort((a, b) => a - b);
    const binatySearch = (v, start, end, target) => {
        while(start <= end) {
            let middle = Math.floor((start + end) / 2);
            if(v[middle] < target) 
                start = middle + 1;
            else if(v[middle] > target)
                end = middle - 1;
            else
                return 1;
        }
        return 0;
    }

    let result = [];
    for(let i = 0; i < num2.length; i++) {
        result.push(binatySearch(num1, 0, num1.length - 1, num2[i]));
    }

    console.log(result.join(' '));
    
    process.exit(0);
});