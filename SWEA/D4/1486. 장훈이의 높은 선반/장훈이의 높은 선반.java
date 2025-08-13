import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
    static int[] arr;
    static int N;
    static int B;
    static int result;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine());

        for (int test_case = 1; test_case <= t; test_case++) {
            String[] NB = br.readLine().split(" ");
            N = Integer.parseInt(NB[0]);
            B = Integer.parseInt(NB[1]);
            result = Integer.MAX_VALUE;

            String[] input = br.readLine().split(" ");
            arr = new int[N];
            for (int i = 0; i < N; i++) {
                int num = Integer.parseInt(input[i]);
                arr[i] = num;
            }

            dfs(0, 0);
            sb.append("#").append(test_case).append(" ").append(result - B).append("\n");
        }
        System.out.println(sb.toString());
    }

    static void dfs(int start, int ret) {
        if(start == N) {
            if(ret >= B) 
                result = Math.min(ret, result);
            
            return;
        }

        dfs(start + 1, ret);
        dfs(start + 1, ret + arr[start]);
    }
}
