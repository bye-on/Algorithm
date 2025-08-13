import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Solution {
    static int N; static int L;
    static boolean[] isSelected;
    static ArrayList<int[]> ham;
    static int result;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int t = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= t; test_case++) {
            String[] NL = br.readLine().split(" ");
            N = Integer.parseInt(NL[0]);
            L = Integer.parseInt(NL[1]);
            
            isSelected = new boolean[N];
            ham = new ArrayList<>();
            result = 0;

            for (int i = 0; i < N; i++) {
                String[] TK = br.readLine().split(" ");
                int T = Integer.parseInt(TK[0]);
                int K = Integer.parseInt(TK[1]);

                ham.add(new int[] {T, K});
            }

            subset(0);
            sb.append("#").append(test_case).append(" ").append(result).append("\n");
        }
        System.out.println(sb);
    }

    static void subset(int cnt) {
        if(cnt == N) {
            int score = 0; int limit = 0;
            for (int i = 0; i < N; i++) {
                if(isSelected[i]) {
                    int[] tmp = ham.get(i);

                    score += tmp[0];
                    limit += tmp[1];
                }
            }

            if(score > result) {
                if(limit <= L) {
                    result = score;
                }
            }
            return;
        }

        isSelected[cnt] = true;
        subset(cnt + 1);

        isSelected[cnt] = false;
        subset(cnt + 1);
    }
}
