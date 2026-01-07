//readline 모듈 불러오기
const readline = require("readline");
//인터페이스 객체 생성하기
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
//입출력 처리하는 코드
let input = [];
rl.on("line", function (line) {
  //입력 처리하는 코드
  input.push(line);
}).on("close", function () {
  //입력을 받은 뒤 실행할 코드
  // 북 동 남 서 (반시계면 (direction + 3) % 4)
  const [dx, dy] = [
    [-1, 0, 1, 0],
    [0, 1, 0, -1],
  ];

  let [N, M] = input[0].split(" ").map(Number);
  let [i, j, direction] = input[1].split(" ").map(Number);

  let map = [];
  for (let col = 2; col < N + 2; col++) {
    let arr = input[col].split(" ").map(Number);
    map.push(arr);
  }

  let visited = Array.from({ length: N }, () => Array(M).fill(false));
  let count = 0;
  const dfs = (x, y, direction, count) => {
    // 1. 현재 칸이 청소되지 않은 경우, 현재 칸을 청소
    if (!visited[x][y]) {
      visited[x][y] = true;
      count++;
    }

    let cleanCount = 0;
    // 3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
    for (let i = 0; i < 4; i++) {
      // 3-1. 반시계 방향으로 90도 회전
      direction = (direction + 3) % 4;
      let nx = x + dx[direction];
      let ny = y + dy[direction];

      if (!visited[nx][ny]) {
        if (map[nx][ny] == 0) {
          // 3-2. 앞쪽 칸이 청소되지 않은 빈 칸인 경우 한 칸 전진
          dfs(nx, ny, direction, count);
          // 3-3. 1번 이동
        } else cleanCount++;
      } else {
        cleanCount++;
      }
    }

    if (cleanCount == 4) {
      // 2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
      // 후진
      let nx = x + dx[(direction + 2) % 4];
      let ny = y + dy[(direction + 2) % 4];

      if (map[nx][ny] == 0) {
        // 2-1. 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 한 칸 후진 후 1번
        dfs(nx, ny, direction, count);
      } else {
        // 2-2. 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 작동을 멈춤
        console.log(count);
        process.exit(); //종료문
      }
    }
    console.log(count);
    process.exit(); //종료문
  };

  dfs(i, j, direction, count);
});
