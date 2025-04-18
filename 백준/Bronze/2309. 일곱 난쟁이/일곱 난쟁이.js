const readline = require('readline');
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
let isCycle = false;

rl.on('line', (line) => {
    // 입력 받는 공간
    input.push(line.trim());
}).on('close', () => {
    // 문제를 풀고 출력하는 공간
    let arr = [];
    let cnt = 0;
    for(let i = 0; i < 9; i++) {
      arr.push(Number(input[i]));
      cnt += Number(input[i]);
    }
    arr.sort((a, b) => a-b);
    
    let ret = cnt - 100;
    const combination = (comb, arr, depth, index) => {
      if(depth == 2) {
        let num = comb[0] + comb[1];
        
        if(num === ret)
        {
          const list = arr.filter((a) => { return !comb.includes(a) ? a : null})
          result.push(list);
        }
        return;
      }

      if(index === arr.length)
        return;

      comb[depth] = arr[index];
      combination(comb, arr, depth + 1, index + 1);
      combination(comb, arr, depth, index + 1);
    }

    let result = []
    let comb = Array(2).fill(0);
    combination(comb, arr, 0, 0);
    console.log(result[0].join('\n'));
});