import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
    static int result;
    static void calc(int[][] map, int N, int M, int x, int y) {
        int cnt = 0;
        for (int i = x; i < x + M; i++) {
            for (int j = y; j < y + M; j++) {
                if(i >= 0 && i < N && j >= 0 && j < N)
                    cnt += map[i][j];
            }
        }
        result = Math.max(result, cnt);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for (int test_case = 1; test_case <= T; test_case++) {
            String[] NM = br.readLine().split(" ");
            int N = Integer.parseInt(NM[0]);
            int M = Integer.parseInt(NM[1]);

            result = 0;

            int[][] map = new int[N][N];
            for (int i = 0; i < N; i++) {
                String[] input = br.readLine().split(" ");
                for (int j = 0; j < N; j++) {
                    int num = Integer.parseInt(input[j]);
                    map[i][j] = num;
                }
            }

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    calc(map, N, M, i, j);
                }
            }

            sb.append("#").append(test_case).append(" ").append(result).append("\n");
        }
        System.out.println(sb.toString());
    }
}
