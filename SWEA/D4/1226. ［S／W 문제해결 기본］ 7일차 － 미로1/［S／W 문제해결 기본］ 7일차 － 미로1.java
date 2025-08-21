import java.util.*;

public class Solution {
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int[][] map = new int[16][16];
    static boolean[][] visited = new boolean[16][16];

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

                if (nx < 0 || ny < 0 || nx >= 16 || ny >= 16) continue;
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

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        for (int test_case = 1; test_case <= 10; test_case++) {
            int T = sc.nextInt();
            System.out.print("#" + T + " ");

            int x = 0, y = 0;
            for (int i = 0; i < 16; i++) {
                String str = sc.next();
                for (int j = 0; j < str.length(); j++) {
                    map[i][j] = str.charAt(j) - '0';
                    visited[i][j] = false;

                    if (map[i][j] == 2) {
                        x = i;
                        y = j;
                    }
                }
            }

            if (bfs(x, y)) System.out.println("1");
            else System.out.println("0");
        }
    }
}
