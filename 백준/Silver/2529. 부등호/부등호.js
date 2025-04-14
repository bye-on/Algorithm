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
    let str = input[1].split(' ');
    
    const d = (visited, index, depth, arr) => {
      if(depth == n) {
        result.push(arr.join(''));
        return;
      }

      if(str[depth] === '<') {
        for(let i = index + 1; i < 10; i++) {
          if(!visited[i]) {
            visited[i] = true;
            arr.push(i);
            d(visited, i, depth + 1, arr);
            arr.pop();
            visited[i] = false;
          }
        }
      }
      else if(str[depth] === '>') {
        for(let i = index - 1; i >= 0; i--) {
          if(!visited[i]) {
            visited[i] = true;
            arr.push(i);
            d(visited, i, depth + 1, arr);
            arr.pop();
            visited[i] = false;
          }
        }
      }
    }

    const arr = [];
    const result = [];
    const visited = Array(10).fill(false);
    for(let i = 0; i < 10; i++) {
      visited[i] = true;
      arr.push(i);
      d(visited, i, 0, arr);
      arr.pop();
      visited[i] = false;
    }

    result.sort();
    console.log(result[result.length - 1]);
    console.log(result[0]);
});