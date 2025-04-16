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
    let arr = input[1].split(' ').map(Number);

    const binary_search = (arr, target, start, end) => { // cpp의 lower_bound 같은 역할
      while(start < end) {
        let middle = Math.floor((start + end) / 2);
        if(arr[middle] < target) 
          start = middle + 1;
        else end = middle; 
      }
      return end;
    }

    let result = 0;
    let lis = [arr[0]];

    for(let i = 1; i < n; i++) {
      if(arr[i] > lis[lis.length - 1]) {
        lis.push(arr[i]);
        result = lis.length - 1;
      }
      let pos = binary_search(lis, arr[i], 0, result);
      lis[pos] = arr[i];
    }

    console.log(result + 1);    
});