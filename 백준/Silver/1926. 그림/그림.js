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
    let dx = [-1, 1, 0, 0];
    let dy = [0, 0, -1, 1];

    let [n, m] = input.shift().split(' ').map(Number);
    let graph = input.slice(0).map((v) => v.split(' ').map(Number));

    let visited = Array.from({length : n + 1}, () => Array(m + 1).fill(false));
    
    const bfs = (graph, visited, x, y) => {
        let q = [];
        q.push([x, y]);
        let leng = 0;

        while(q.length) {
            let [x, y] = q.shift();
            visited[x][y] = true;
            leng++;

            for(let i = 0; i < 4; i++) {
                let nx = x + dx[i];
                let ny = y + dy[i];

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(!visited[nx][ny] && graph[nx][ny] === 1) {
                    visited[nx][ny] = true;
                    q.push([nx, ny]);
                }
            }
        }
        max = Math.max(max, leng);
    }

    let cnt = 0;
    let max = 0;
    for(let i = 0; i < n; i++) {
        for(let j = 0; j < m; j++) {
            if(!visited[i][j] && graph[i][j] === 1) {
                cnt++;
                bfs(graph, visited, i, j);
            }
        }
    }

    console.log(cnt);
    console.log(max);
});