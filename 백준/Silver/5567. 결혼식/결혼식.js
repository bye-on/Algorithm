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
    let n = Number(input.shift());
    let m = Number(input.shift());
    let line = input.map((v) => v.split(' ').map(Number));

    let graph = Array.from({length : n + 1}, () => []);
    for(let [a, b] of line) {
        graph[a].push(b);
        graph[b].push(a);
    }

    for(let i = 0; i <= n; i++) {
        graph[i].sort((a,b) => a-b);
    }

    let visited = Array(n + 1).fill(false);
    const bfs = (v, visited) => {
        let depth = 0;
        let cnt = 0;

        let q = [];
        q.push([v, depth]);

        while(q.length) {
            let [start, depth] = q.shift();
            visited[start] = true;

            if(depth == 2)
                break;
            
            for(let i = 0; i < graph[start][i]; i++) {
                let next = graph[start][i];
                if(!visited[next]) {
                    cnt++;
                    q.push([next, depth+1]);
                    visited[next] = true;
                }
            }
        }

        return cnt;
    };

    let cnt = 0;
    cnt = Math.max(cnt, bfs(1, visited));
    console.log(cnt);
});