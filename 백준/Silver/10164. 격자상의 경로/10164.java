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

        int[][] dp = new int[n][m];

        int num = 1;
        int y = 0;
        int x = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(num == k) {
                    y = i;
                    x = j;
                }
                num++;
            }
        }

        for (int i = 0; i <= y; i++) {
            for (int j = 0; j <= x; j++) {
                if (i == 0 && j == 0)
                    dp[i][j] = 1;
                else if (i == 0)
                    dp[i][j] = 1;
                else if (j == 0)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        int num1 = dp[y][x];

        for (int i = y; i < n; i++) {
            for (int j = x; j < m; j++) {
                if (i == y && j == x)
                    dp[i][j] = 1;
                else if (i == y)
                    dp[i][j] = 1;
                else if (j == x)
                    dp[i][j] = 1;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        int num2 = dp[n - 1][m - 1];

        System.out.println(num1 * num2);
    }
}