import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Solution
{
    static int[][] map;
    static int x; static int y;

    static int[] dx = {0, 0, -1};
    static int[] dy = {-1, 1, 0};

    static boolean checkLeft() {
        int nx = x + dx[0];
        int ny = y + dy[0];

        if(nx < 0 || nx >= 100 || ny < 0 || ny >= 100) return false;
        if(map[nx][ny] == 0) return false;
        
        return true;
    }

    static boolean checkRight() {
        int nx = x + dx[1];
        int ny = y + dy[1];

        if(nx < 0 || nx >= 100 || ny < 0 || ny >= 100) return false;
        if(map[nx][ny] == 0) return false;
        
        return true;
    }

	public static void main(String args[]) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        
		for(int test_case = 1; test_case <= 10; test_case++)
		{
            int T = Integer.parseInt(br.readLine());
            map = new int[100][100];
            x = 0; y = 0;

            for (int i = 0; i < 100; i++) {
                String[] input = br.readLine().split(" ");
                for (int j = 0; j < input.length; j++) {
                    int num = Integer.parseInt(input[j]);
                    
                    if(num == 2) {
                        x = i;
                        y = j;
                    }

                    map[i][j] = num;
                }
            }


            while (x != 0) {
                if(checkLeft()) {
                    while (true) {
                        int nx = x + dx[0];
                        int ny = y + dy[0];

                        if(nx < 0 || nx >= 100 || ny <0 || ny>= 100) {
                            nx = x + dx[2];
                            ny = y + dy[2];

                            if(map[nx][ny] == 1) {
                                x = nx;
                                y = ny;
                            }

                            break;
                        }
                        if(map[nx][ny] == 0) {
                            nx = x + dx[2];
                            ny = y + dy[2];

                            if(map[nx][ny] == 1) {
                                x = nx;
                                y = ny;
                            }

                            break;
                        }
                        if(map[nx][ny] == 1) {
                            x = nx;
                            y = ny;
                        }
                    }
                } else if(checkRight()) {
                    while (true) {
                        int nx = x + dx[1];
                        int ny = y + dy[1];

                        if(nx < 0 || nx >= 100 || ny <0 || ny>= 100) {
                            nx = x + dx[2];
                            ny = y + dy[2];

                            if(map[nx][ny] == 1) {
                                x = nx;
                                y = ny;
                            }

                            break;
                        }
                        if(map[nx][ny] == 0) {
                            nx = x + dx[2];
                            ny = y + dy[2];

                            if(map[nx][ny] == 1) {
                                x = nx;
                                y = ny;
                            }

                            break;
                        }
                        if(map[nx][ny] == 1) {
                            x = nx;
                            y = ny;
                        }
                    }
                } else {
                    int nx = x + dx[2];
                    int ny = y + dy[2];

                    if(map[nx][ny] == 1) {
                        x = nx;
                        y = ny;
                    }
                }
            }

            sb.append("#").append(T).append(" ").append(y).append("\n");
		}
        System.out.println(sb.toString());
	}
}