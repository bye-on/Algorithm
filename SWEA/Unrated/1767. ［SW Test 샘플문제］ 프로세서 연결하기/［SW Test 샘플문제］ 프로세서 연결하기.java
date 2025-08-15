import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Solution {

    static int[][] map;
    static int n;

    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};

    static ArrayList<int[]> arr;

    static int coreCount;
    static int lineCount;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int t = Integer.parseInt(br.readLine());

        for (int test_case = 1; test_case <= t; test_case++) {
            n = Integer.parseInt(br.readLine());

            map = new int[n][n];
            arr = new ArrayList<>();

            coreCount = 0;
            lineCount = Integer.MAX_VALUE;

            for (int i = 0; i < n; i++) {
                String[] input = br.readLine().split(" ");
                for (int j = 0; j < n; j++) {
                    int num = Integer.parseInt(input[j]);
                    map[i][j] = num;

                    if(i > 0 && i < n - 1 && j > 0 && j < n - 1 && (num == 1)) {
                        arr.add(new int[]{i, j});
                    }
                }
            }

            calc(0, 0, 0);

            sb.append("#").append(test_case).append(" ").append(lineCount).append("\n");
        }
        System.out.println(sb.toString());
    }

    public static boolean pruning(int i, int j, int direction) {
        int nx = i; int ny = j;

        while (true) {
            nx += dx[direction];
            ny += dy[direction];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) break;
            if(map[nx][ny] != 0) return false;
        }

        return true;
    }

    public static int setting(int i, int j, int direction, int set) {
        int nx = i; int ny = j;

        int cnt = 0;
        while (true) {
            nx += dx[direction];
            ny += dy[direction];

            if(nx < 0 || nx >= n || ny < 0 || ny >= n) break;
            if(set == 1) { // on
                map[nx][ny] = 2;
                cnt++;
            }   
            else if(set == 0) { // off
                map[nx][ny] = 0;
            }
        }

        return cnt;
    }

    public static void calc(int index, int cCnt, int lCnt) {
        // cCnt : core count, lCnt: line count
        if(index == arr.size()) {
            if(coreCount < cCnt) {
                coreCount = cCnt;
                lineCount = lCnt;
            } else if(coreCount == cCnt) {
                lineCount = Math.min(lineCount, lCnt);
            }

            return;
        }


        int x = arr.get(index)[0];
        int y = arr.get(index)[1];

        for (int d = 0; d < 4; d++) {
            
            if(pruning(x, y, d)) {
                int cnt = setting(x, y, d, 1);
                calc(index + 1, cCnt + 1, lCnt + cnt);
                setting(x, y, d, 0);
            }
        }

        calc(index + 1, cCnt, lCnt);
    }
}