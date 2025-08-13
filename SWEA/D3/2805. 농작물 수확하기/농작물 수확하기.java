import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int t = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= t; test_case++) {
            int n = Integer.parseInt(br.readLine());

            int[][] map = new int[n][n];
            for (int i = 0; i < n; i++) {
                String[] str = br.readLine().split("");
                for (int j = 0; j < n; j++) {
                    map[i][j] = Integer.parseInt(str[j]);
                }
            }

            int result = 0;
            for (int i = 0; i < n; i++) {
                int start = Math.abs((n / 2) - i);
                int end = n - start - 1;
                
                for (int j = start; j <= end; j++) {
                    result += map[i][j];
                }
            }
            
            sb.append("#").append(test_case).append(" ").append(result).append("\n");
        }
        System.out.println(sb);
    }
}
