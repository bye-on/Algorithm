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
    let T = Number(input.shift());
    for(let i = 0; i < T; i++) {
      let front = false;
      let err = false;

      let p = input.shift();
      let num = Number(input.shift());
      let str = input.shift();
      let l = [];
      if(str.length > 2)
        l = str.slice(1, str.length - 1).split(',').map(Number);

      for(let j = 0; j < p.length; j++) {
        if(p[j] === 'R') {
          front = !front;
        }
        else if(p[j] === 'D') {
          if(l.length > 0) {
            if(!front) 
              l.shift();
            else
              l.pop();
          }
          else {
            err = true;
            break;
          }
        }
      }
      if(!err) {
        if(front)
          l.reverse();
        console.log(`[${l.join(',')}]`);
      }
      else
        console.log("error");
    }
});