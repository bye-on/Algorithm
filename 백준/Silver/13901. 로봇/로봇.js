const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

let input = [];
rl.on("line", (line) => {
  // 입력 받는 공간
  input.push(line.trim());
}).on("close", () => {
  // 문제를 풀고 출력하는 공간
  let [r, c] = input[0].split(" ").map(Number);
  let k = Number(input[1]);

  let map = Array.from({ length: r }, () => Array(c).fill("*"));

  for (let i = 0; i < k; i++) {
    let [br, bc] = input[2 + i].split(" ").map(Number);
    map[br][bc] = "x";
  }

  let [sr, sc] = input[input.length - 2].split(" ").map(Number);
  let dir = input[input.length - 1].split(" ").map(Number);

  let visited = Array.from({ length: r }, () => Array(c).fill(false));
  let count = 0;

  let dx = [-1, 1, 0, 0];
  let dy = [0, 0, -1, 1];

  const calc = (sr, sc, direction, visited, map) => {
    visited[sr][sc] = true;
    map[sr][sc] = count++;
    let endCnt = 0;

    while (true) {
      let nr = sr + dx[dir[direction] - 1];
      let nc = sc + dy[dir[direction] - 1];

      if (endCnt >= 4) break;
      if (nr < 0 || nc < 0 || nr >= r || nc >= c) {
        direction = (direction + 1) % 4;
        endCnt++;
        continue;
      }

      if (!visited[nr][nc] && map[nr][nc] === "*") {
        map[nr][nc] = count++;
        visited[nr][nc] = true;
        sr = nr;
        sc = nc;
        endCnt = 0;
      } else {
        direction = (direction + 1) % 4;
        endCnt++;
      }
    }

    return [sr, sc];
  };

  console.log(calc(sr, sc, 0, visited, map).join(" "));
});
