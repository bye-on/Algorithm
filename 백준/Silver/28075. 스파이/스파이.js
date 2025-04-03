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
    let [n, m] = input.shift().split(' ').map(Number);
    let matrix = input.slice(0).map((v) => v.split(' ').map(Number));
    
    let result = 0;
    const recur = (cnt, answer, index) => {
        if(cnt == n)
        {
            if(answer >= m) {
                result++;
            }
            return;
        }
            
        for(let i = 0; i < 2; i++) {
            for(let j = 0; j < 3; j++) {
                if(index == j)
                    recur(cnt + 1, answer + Math.floor(matrix[i][j] / 2), j);
                else
                    recur(cnt + 1, answer + matrix[i][j], j);
            }
        }
    }   

    recur(0, 0, -1);
    console.log(result);
});