import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {

    static char[][] map;

    // ^ < v > (상 좌 하 우)
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};

    static int H; static int W;

    static int direction;
    static int x;
    static int y;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());

        for (int test_case = 1; test_case <= t; test_case++) {
            String[] HW = br.readLine().split(" ");
            H = Integer.parseInt(HW[0]);
            W = Integer.parseInt(HW[1]);

            x = -1; y = -1;

            map = new char[H][W];
            for (int i = 0; i < H; i++) {
                String input = br.readLine();
                for (int j = 0; j < W; j++) {
                    map[i][j] = input.charAt(j);

                    if(map[i][j] == '^') {
                        x = i; y = j;  
                        direction = 0;
                    }
                    if(map[i][j] == '<') {
                        x = i; y = j;
                        direction = 1;
                    }
                    if(map[i][j] == 'v') {
                        x = i; y = j;
                        direction = 2;
                    }
                    if(map[i][j] == '>') {
                        x = i; y = j;
                        direction = 3;
                    }
                }
            }

            int N = Integer.parseInt(br.readLine());
            String str = br.readLine();

            for (int i = 0; i < N; i++) {
                char c = str.charAt(i);
                calc(c);
            }

            sb.append("#").append(test_case).append(" ");
            for (int i = 0; i < H; i++) {
                for (int j = 0; j < W; j++) {
                    sb.append(map[i][j]);
                }
                sb.append("\n");
            }
        }
        System.out.println(sb);
    }

    static void calc(char c) {
        if(c == 'S') {
            int nx = x;
            int ny = y;

            while (true) {
                nx += dx[direction];
                ny += dy[direction];

                if(nx < 0 || nx >= H || ny < 0 || ny >= W) break;
                if(map[nx][ny] == '.') continue;
                if(map[nx][ny] == '-') continue;
                if(map[nx][ny] == '#') break;
                if(map[nx][ny] == '*') {
                    map[nx][ny] = '.';
                    break;
                }
            }
        }

        if(c == 'U') {
            direction = 0;
            int nx = x + dx[direction];
            int ny = y + dy[direction];

            map[x][y] = '^';
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) {
                return;
            }
            if(map[nx][ny] == '.') {
                map[x][y] = '.';
                map[nx][ny] = '^';
                x = nx; y = ny;
            }
        }

        if(c == 'D') {
            direction = 2;
            int nx = x + dx[direction];
            int ny = y + dy[direction];
            map[x][y] = 'v';

            if(nx < 0 || nx >= H || ny < 0 || ny >= W) {
                return;
            }
            if(map[nx][ny] == '.') {
                map[x][y] = '.';
                map[nx][ny] = 'v';
                x = nx; y = ny;
            }
        }

        if(c == 'L') {
            direction = 1;
            int nx = x + dx[direction];
            int ny = y + dy[direction];

            map[x][y] = '<';
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) {
                return;
            }
            if(map[nx][ny] == '.') {
                map[x][y] = '.';
                map[nx][ny] = '<';
                x = nx; y = ny;
            }
        }

        if(c == 'R') {
            direction = 3;
            int nx = x + dx[direction];
            int ny = y + dy[direction];

            map[x][y] = '>';
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) {
                return;
            }
            if(map[nx][ny] == '.') {
                map[x][y] = '.';
                map[nx][ny] = '>';
                x = nx; y = ny;
            }
        }
    }
}