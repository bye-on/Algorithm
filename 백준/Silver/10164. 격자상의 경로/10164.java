import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] str = br.readLine().split(" ");
        int n = Integer.parseInt(str[0]);
        int m = Integer.parseInt(str[1]);
        int k = Integer.parseInt(str[2]);

        int[][] dp = new int[n + 1][m + 1];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0)
                    dp[i][j] = 0;
                else if (i == 0)
                    dp[i][j] = 1;
                else if (j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        int y = (k - 1) / m;
        int x = (k % m) - 1;

        int cnt = 0;
        if(k != 0) {
            for (int i = 0; i < x; i++) {
                cnt += dp[y + 1][i];
            }
            for (int i = x + 1; i < m; i++) {
                cnt += dp[y - 1][i];
            }
        }

        System.out.println(dp[n - 1][m - 1] - cnt);
    }
}