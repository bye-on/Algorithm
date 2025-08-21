import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int[][] map = new int[100][100];
    static boolean[][] visited = new boolean[100][100];

    public static boolean bfs(int x, int y) {
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{x, y});
        visited[x][y] = true;

        while (!q.isEmpty()) {
            int[] cur = q.poll();
            x = cur[0];
            y = cur[1];

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx < 0 || ny < 0 || nx >= 100 || ny >= 100) continue;
                if (!visited[nx][ny]) {
                    if (map[nx][ny] == 0) {
                        visited[nx][ny] = true;
                        q.offer(new int[]{nx, ny});
                    }
                    if (map[nx][ny] == 3) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        for (int test_case = 1; test_case <= 10; test_case++) {
            int T = Integer.parseInt(br.readLine());

            int x = 0, y = 0;
            for (int i = 0; i < 100; i++) {
                String str = br.readLine();
                for (int j = 0; j < str.length(); j++) {
                    map[i][j] = str.charAt(j) - '0';
                    visited[i][j] = false;

                    if (map[i][j] == 2) {
                        x = i;
                        y = j;
                    }
                }
            }

            sb.append("#").append(T).append(" ");
            if (bfs(x, y)) sb.append("1\n");
            else sb.append("0\n");
        }

        System.out.print(sb);
    }
}
