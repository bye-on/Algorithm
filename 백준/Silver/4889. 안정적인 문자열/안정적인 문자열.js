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
    let a = input.slice();
    for(let i = 0; i < (a.length - 1); i++) {
        let stack = [];
        for(let j = 0; j < a[i].length; j++) {
            if(!stack.length)
                stack.push(a[i][j]);
            else if(a[i][j] === '{')
                stack.push(a[i][j]);
            else if(a[i][j] === '}') {
                let c = stack[stack.length - 1];
                if(c === '{')
                    stack.pop();
                else
                    stack.push(a[i][j]);
            }
        }

        let cnt = 0;
        while(stack.length) {
            let c1 = stack.pop();
            let c2 = stack.pop();

            if(c1 === c2) {
                cnt++;
            }
            else {
                cnt += 2;
            }
        }

        console.log(`${i + 1}. ${cnt}`);
    }
});