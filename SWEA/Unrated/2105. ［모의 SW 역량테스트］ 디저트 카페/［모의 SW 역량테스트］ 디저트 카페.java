import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Solution {
    static int[][] map;
    static int n;

    static int[] dx = {1, 1, -1, -1};
    static int[] dy = {1, -1, -1, 1};

    static int max;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine());

        for (int test_case = 1; test_case <= T; test_case++) {
            n = Integer.parseInt(br.readLine());
            max = -1;

            map = new int[n][n];
            int maxnum = 0;
            for (int i = 0; i < n; i++) {
                String[] input = br.readLine().split(" ");
                for (int j = 0; j < n; j++) {
                    int num = Integer.parseInt(input[j]);
                    map[i][j] = num;
                    maxnum = Math.max(maxnum, num);
                }
            }

            // start index > 처음 위치, 현재 위치
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    Set<Integer> s = new HashSet<>();
                    dfs(0, i, j, i, j, 0, s);
                }
            }

            sb.append("#").append(test_case).append(" ").append(max).append("\n");
        }
        System.out.println(sb);
    }

    static void dfs(int index, int x, int y, int cx, int cy, int ret, Set<Integer> set) {
        if(index == 4) {
            if(x == cx && y == cy) {
                if(ret > 0) 
                    max = Math.max(ret, max);
            }
            return;
        }
        
        if(!set.contains(map[cx][cy]))
            set.add(map[cx][cy]);
        else
            return;

        int nx = cx + dx[index];
        int ny = cy + dy[index];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n) return;
    
        // 방향 꺾기
        dfs(index + 1, x, y, nx, ny, ret + 1, new HashSet<>(set));
        // 방향 그대로
        dfs(index, x, y, nx, ny, ret + 1, new HashSet<>(set));
    }
}
