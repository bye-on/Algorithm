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
    let line = input.map((v) => v.split(' ').map(Number));
    let graph = Array.from({ length : n + 1 }, () => []);
    
    for(let [from, to] of line) {
        graph[from].push(to);
        graph[to].push(from);
    }

    for(let i = 0; i <= n; i++)
        graph[i].sort((a, b) => a - b);

    const bfs = (graph, start, d) => {
        const q = [];
        d[start] = 0;
        q.push(start);

        while(q.length) {
            let v = q.pop();
            let depth = d[v] + 1;
            
            for(let node of graph[v])
            {
                if(d[node] > depth)
                {
                    d[node] = depth;
                    q.push(node);
                }
            }
        }
    }

    const result = [];
    for(let i = 1; i <= n; i++)
    {
        const d = Array(n + 1).fill(Infinity);
        bfs(graph, i, d);
        
        let cnt = 0;
        for(let j = 1; j <= n; j++)
            cnt += d[j];

        result.push([cnt, i]);
    }

    result.sort(function(a, b) {
        if(a[0] == b[0])
            return a[1] - b[1];
        return a[0] -  b[0];
    });
    console.log(result.shift()[1]);

    process.exit(0);
});