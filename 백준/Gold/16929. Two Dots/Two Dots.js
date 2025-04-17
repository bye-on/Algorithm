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
    let [n, m] = input[0].split(' ').map(Number);
    let graph = Array.from({length: n}, ()=>[]);
    for(let i = 1; i <= n; i++) {
      for(let j = 0; j < m; j++) {
        graph[i - 1].push(input[i][j]);
      }
    }
    
    let visited = Array.from({length: n}, () => Array(m).fill(false));
    const dx = [-1, 1, 0, 0];
    const dy = [0, 0, -1, 1];
    let isCycle = false;   
    let [x, y] = [0, 0];

    const dfs = (i, j, cnt) => {
      if(isCycle)
        return;

      for(let t = 0; t < 4; t++) {
        const [nx, ny] = [i + dx[t], j + dy[t]];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(graph[x][y] === graph[nx][ny]) {
          if(!visited[nx][ny]) {
            visited[nx][ny] = true;
            dfs(nx, ny, cnt + 1);
            visited[nx][ny] = false;
          }
          else if(nx === x && ny === y && cnt >= 4) {
            isCycle = true;
            return;
          }
        }
      }
    }

    for(let i = 0; i < n; i++) {
      for(let j = 0; j < m; j++) {
        [x, y] = [i, j];
        visited[i][j] = true;
        dfs(i, j, 1);
        visited[i][j] = false;
        if(isCycle) break;
      }
    }

    if(isCycle)
      console.log("Yes");
    else
      console.log("No");
});