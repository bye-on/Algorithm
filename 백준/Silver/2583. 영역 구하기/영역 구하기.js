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
    let [n, m, k] = input[0].split(' ').map(Number);
    let graph = Array.from(Array(n), ()=> Array(m).fill(0));
    
    for(let i = 0; i < k; i++) {
      let [x1, y1, x2, y2] = input[1 + i].split(' ').map(Number);
      for(let i = y1; i < y2; i++) {
        for(let j = x1; j < x2; j++) {
          graph[i][j] = 1;
        }
      }
    }

    let visited = Array.from(Array(n), () => Array(m).fill(false));
    const dx = [-1, 1, 0, 0];
    const dy = [0, 0, -1, 1];

    const bfs = (visited, x, y) => {
      let q = [];
      q.push([x, y]);
      let cnt = 0;

      while(q.length) {
        let [x, y] = q.shift();
        visited[x][y] = true;
        cnt++;

        for(let i = 0; i < 4; i++) {
          let nx = x + dx[i];
          let ny = y + dy[i];

          if(nx < 0 || ny < 0 || nx >= n || ny >= m) 
            continue;
          if(!visited[nx][ny] && graph[nx][ny] === 0) {
            visited[nx][ny] = true;
            q.push([nx, ny]);
          }
        }
      }

      return cnt;
    }

    let list = [];
    for(let i = 0; i < n; i++) {
      for(let j = 0; j < m; j++) {
        if(!visited[i][j] && graph[i][j] === 0) {
          list.push(bfs(visited, i, j));
        }
      }
    }

    list.sort((a, b) => a-b);
    console.log(list.length);
    console.log(list.join(' '));
});