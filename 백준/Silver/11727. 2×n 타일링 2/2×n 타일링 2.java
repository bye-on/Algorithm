import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static int[] memo = new int[1001];
    public static int tiling(int n) {
        if(n == 1) return 1;
        if(n == 2) return 3;
        if(memo[n] == 0) {
            memo[n] = (tiling(n - 1) + 2 * tiling(n - 2)) % 10007;
        }
        return memo[n];
    }
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(bf.readLine());
        System.out.println(tiling(n));
    }
}
