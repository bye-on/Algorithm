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
    let [n, m, v] = input.shift().split(' ').map(Number);
    let line = input.map((v) => v.split(' ').map(Number));
    let graph = Array.from({ length : n + 1 }, () => []);
    
    for(let [from, to] of line) {
        graph[from].push(to);
        graph[to].push(from);
    }

    for(let i = 0; i <= n; i++)
        graph[i].sort((a, b) => a - b);

    const d = [];
    const dfs = (graph, start, visited) => {
        d.push(start);
        visited[start] = true;

        for(let node of graph[start])
        {
            if(!visited[node])
                dfs(graph, node, visited);
        }
    }

    const b = [];
    const bfs = (graph, start, visited) => {
        const q = [];
        q.push(start);

        while(q.length) {
            let v = q.shift();
            visited[v] = true;
            b.push(v);
            
            for(let node of graph[v])
                if(!visited[node])
                {
                    visited[node] = true;
                    q.push(node);
                }
        }
    }

    let visited = Array(n).fill(false);
    dfs(graph, v, visited);
    visited = Array(n).fill(false);
    bfs(graph, v, visited);

    const dr = d.join(' ');
    const br = b.join(' ');
    console.log(dr);
    console.log(br);

    process.exit(0);
});