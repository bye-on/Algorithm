import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int t = Integer.parseInt(br.readLine());

        for (int test_case = 1; test_case <= t; test_case++) {
            double num = Long.parseLong(br.readLine());

            if(num == 2) {
                sb.append("#").append(test_case).append(" ").append(0).append("\n");
                continue;
            }

            long cnt = 0;
            while (true) {
                if(num <= 2) {
                    sb.append("#").append(test_case).append(" ").append(cnt).append("\n");
                    break;
                }

                double a = Math.sqrt(num);
                if((long) a == a) { // 정수인지 아닌지 판별
                    cnt++;
                    num = a;
                } else { // 정수가 아니라면
                    long b = (long) (Math.sqrt(num) + 1);
                    long c = b * b;
                    cnt += (long) (c - num);
                    num = c;
                }
            }
        }
        System.out.println(sb);
    }
}
