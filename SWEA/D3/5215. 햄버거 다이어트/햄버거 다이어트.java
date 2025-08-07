import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Solution {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for (int test_case = 1; test_case <= T; test_case++) {
            String[] NL = br.readLine().split(" ");
            int N = Integer.parseInt(NL[0]); // 재료의 수
            int L = Integer.parseInt(NL[1]); // 제한 칼로리

            int[][] arr = new int[N + 1][2];
            for (int i = 1; i <= N; i++) {
                String[] TK = br.readLine().split(" ");
                int t = Integer.parseInt(TK[0]);
                int k = Integer.parseInt(TK[1]);
                arr[i][0] = t; // 점수
                arr[i][1] = k; // 칼로리
            }

            int[][] dp = new int[N + 1][L + 1]; // [번호][칼로리], value = 점수
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= L; j++) {
                    int value = arr[i][0];
                    int calorie = arr[i][1];

                    if (calorie > j)
                        dp[i][j] = dp[i - 1][j];
                    else
                        dp[i][j] = Math.max(dp[i - 1][j], value + dp[i - 1][j - calorie]);
                }
            }

            sb.append("#").append(test_case).append(" ").append(dp[N][L]).append("\n");
        }
        System.out.println(sb.toString());
    }
}