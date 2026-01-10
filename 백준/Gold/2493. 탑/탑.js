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

  let result = [0];
  let stack = [[arr[0], 1]];
  for (let i = 1; i < n; i++) {
    let len = stack.length - 1;

    let [num, index] = stack[len];
    if (num > arr[i]) {
      result.push(index);
      stack.push([arr[i], i + 1]);
    } else {
      while (!!stack.length) {
        let [num, index] = stack.pop();
        if (num > arr[i]) {
          stack.push([num, index]);
          break;
        }
      }

      if (!!stack.length) {
        let [num, index] = stack[stack.length - 1];
        result.push(index);
      } else {
        result.push(0);
      }
      stack.push([arr[i], i + 1]);
    }
  }

  console.log(result.join(" "));
  process.exit(); //종료문
});
