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
  let n = Number(input[0]);
  let arr = input[1].split(" ").map(Number);
  let m = Number(input[2]);

  let start = 1;
  let end = Math.max(...arr);
  let answer = 0;
  while (start <= end) {
    let middle = Math.floor((start + end) / 2);
    let result = 0;
    for (let i = 0; i < arr.length; i++) {
      if (arr[i] < middle) result += arr[i];
      else result += middle;
    }

    if (result > m) {
      end = middle - 1;
    } else {
      answer = middle;
      start = middle + 1;
    }
  }

  console.log(answer);
  process.exit(); //종료문
});
