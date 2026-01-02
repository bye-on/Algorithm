const readline = require("readline");
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});
let input = [];
rl.on("line", function (line) {
  input.push(line);
}).on("close", function () {
  let [S, T] = input;
  // 뒤집어서 마무리할 지 판단
  let isReverse = false;

  let start = 0;
  let end = T.length - 1;
  while (end - start + 1 != S.length) {
    if (!isReverse) {
      let ch = T.charAt(end--);

      if (ch == "B") {
        isReverse = !isReverse;
      }
    } else {
      let ch = T.charAt(start++);

      if (ch == "B") {
        isReverse = !isReverse;
      }
    }
  }

  let result = T.slice(start, end + 1);
  if (isReverse) result = result.split("").reverse().join("");

  if (result === S) console.log(1);
  else console.log(0);

  process.exit(); //종료문
});
