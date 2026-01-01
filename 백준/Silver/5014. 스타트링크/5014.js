//readline 모듈 불러오기
const readline = require("readline");
//인터페이스 객체 생성하기
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
//입출력 처리하는 코드
rl.on("line", function (line) {
  //입력 처리하는 코드
  let [F, S, G, U, D] = line.split(" ").map(Number);
  let loc = new Array(F + 1).fill(false);

  let useStair = false;
  let count = 0;
  while (true) {
    if (S == G) break;

    if (loc[S]) {
      useStair = true;
      break;
    } else {
      loc[S] = true;
    }

    if (S + U < G) {
      if (U != 0) {
        let up = Math.floor((G - S) / U);
        count += up;
        S += up * U;
      }
    } else if (S + U > G) {
      count++;

      if (S - D > 0) S -= D;
      else {
        if (S + U <= F) S += U;
      }
    } else {
      count++;
      break;
    }
  }

  if (useStair) console.log("use the stairs");
  else console.log(count);

  rl.close();
}).on("close", function () {
  //입력을 받은 뒤 실행할 코드
  process.exit(); //종료문
});
