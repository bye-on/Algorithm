import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static boolean[][] visited;

    static int[] dx = { -1, 0, 1 };
    static int[] dy = { 1, 1, 1 };

    static int R;
    static int C;
    static int result;

    static boolean check;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] RC = br.readLine().split(" ");
        R = Integer.parseInt(RC[0]);
        C = Integer.parseInt(RC[1]);

        visited = new boolean[R][C];
        result = 0;

        for (int i = 0; i < R; i++) {
            String[] str = br.readLine().split("");
            for (int j = 0; j < C; j++) {
                if (str[j].equals("x"))
                    visited[i][j] = true;
            }
        }

        for (int i = 0; i < R; i++) {
            check = false;
            dfs(i, 0);
        }

        System.out.println(result);
    }

    static void dfs(int i, int j) {

        if (j == (C - 1)) {
            result++;
            check = true;
            return;
        }

        for (int k = 0; k < 3; k++) {
            if (check) {
                return;
            }

            int nx = i + dx[k];
            int ny = j + dy[k];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                continue;

            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                dfs(nx, ny);
            }
        }
    }
}
