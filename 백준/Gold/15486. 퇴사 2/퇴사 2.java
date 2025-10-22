import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] dp = new int[n + 1];

        int prev = 0;
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int t = Integer.parseInt(st.nextToken());
            int p = Integer.parseInt(st.nextToken());
            dp[i] = Math.max(dp[i], prev);
            prev = Math.max(dp[i], prev);

            if (t + i <= n) {
                dp[t + i] = Math.max(p + dp[i], dp[t + i]);
            }
        }

        System.out.println(Math.max(dp[n], prev));
    }
}
