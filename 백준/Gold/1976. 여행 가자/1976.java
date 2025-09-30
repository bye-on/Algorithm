import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        long[][] map = new long[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                int num = Integer.parseInt(st.nextToken());
                map[i][j] = num;
                
                if(i == j)
                    map[i][j] = 1;
                else {
                    if(num == 0)
                        map[i][j] = Integer.MAX_VALUE;
                    if(num == 1)
                        map[i][j] = 1;
                }
            }
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    map[i][j] = Math.min(map[i][j], map[i][k] + map[k][j]);
                }
            }
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken());
        boolean isConnected = true;
        for (int i = 1; i < m; i++) {
            int next = Integer.parseInt(st.nextToken());

            if(map[start][next] >= Integer.MAX_VALUE) {
                isConnected = false;
                break;
            }

            start = next;
        }

        if(isConnected) 
            System.out.println("YES");
        else
            System.out.println("NO");
    }
}
