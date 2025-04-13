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

    let stack = [];
    let result = [];
    for(let i = 1; i <= n; i++) {
      let [command, m] = input[i].split(' ');
      switch(command) {
        case 'push':
          stack.push(Number(m));
          break;
        case 'pop':
          if(stack.length) 
            result.push(stack.pop());
          else 
            result.push(-1);
          break;
        case 'size':
          result.push(stack.length);
          break;
        case 'empty':
          if(stack.length)
            result.push(0);
          else 
            result.push(1);
          break;
        case 'top':
          if(stack.length)
            result.push(stack[stack.length - 1]);
          else
            result.push(-1);
          break;
      }
    }

    console.log(result.join('\n'));
});