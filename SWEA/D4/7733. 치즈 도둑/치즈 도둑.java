import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class Solution {
    static int[][] map;
    static boolean[][] visited;

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};

    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for (int test_case = 1; test_case <= T; test_case++) {
            n = Integer.parseInt(br.readLine());
            map = new int[n][n];

            PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
                @Override
                public int compare(int[] o1, int[] o2) {
                    // TODO Auto-generated method stub
                    return o1[0] - o2[0];
                }
            });

            int max = 1; int min = Integer.MAX_VALUE;
            for (int i = 0; i < n; i++) {
                String[] input = br.readLine().split(" ");
                for (int j = 0; j < n; j++) {
                    int num = Integer.parseInt(input[j]);
                    map[i][j] = num;
                    pq.add(new int[] {num, i, j});
                    min = Math.min(min, num);
                }
            }

            while (!pq.isEmpty()) {
                while (!pq.isEmpty()) {
                    int[] current = pq.poll();
                    int height = current[0];
                    int x = current[1];
                    int y = current[2];

                    if(height != min) {
                        min = height;
                        pq.add(new int[] {height, x, y});
                        break;
                    }

                    map[x][y] -= min;
                }
                
                visited = new boolean[n][n];
                int cnt = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if(!visited[i][j] && map[i][j] > 0) {
                            bfs(i, j);
                            cnt ++;
                        }
                    }
                }
                max = Math.max(max, cnt);
            }

            sb.append("#").append(test_case).append(" ").append(max).append("\n");
        }
        System.out.println(sb);
    }

    static void bfs(int x, int y) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] {x, y});
        
        while (!q.isEmpty()) {
            int[] current = q.poll();
            int i = current[0];
            int j = current[1];
            visited[i][j] = true;

            for (int d = 0; d < 4; d++) {
                int nx = i + dx[d];
                int ny = j + dy[d];

                if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                if(!visited[nx][ny] && map[nx][ny] > 0) {
                    visited[nx][ny] = true;
                    q.add(new int[] { nx, ny });
                }
            }
        }
    }
}
