import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};

    static int n;
    static int result;

    static int[][] map;
    static boolean[][] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int t = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= t; test_case++) {
            n = Integer.parseInt(br.readLine());

            result = 0;
            map = new int[n][n];
            visited = new boolean[n][n];

            for (int i = 0; i < n; i++) {
                String[] input = br.readLine().split("");
                for (int j = 0; j < n; j++) {
                    int num = Integer.parseInt(input[j]);
                    map[i][j] = num;
                }
            }

            calc(n/2, n/2);
            sb.append("#").append(test_case).append(" ").append(result).append("\n");
        }
        System.out.println(sb);
    }

    static void calc(int i, int j) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] {i, j, 0});

        while (!q.isEmpty()) {
            int[] current = q.poll();
            int x = current[0];
            int y = current[1];
            int depth = current[2];
            
            if(!visited[x][y]) {
                visited[x][y] = true;
                result += map[x][y];
            }

            if (depth == n / 2)
                break;

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];
        
                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(!visited[nx][ny]) {
                    visited[nx][ny] = true;
                    result += map[nx][ny];
        
                    q.add(new int[] {nx, ny, depth + 1});
                }
            }
        }
    }
}
