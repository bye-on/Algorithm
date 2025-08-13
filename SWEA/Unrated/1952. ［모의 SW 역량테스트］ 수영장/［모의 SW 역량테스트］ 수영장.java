import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
    static int[] costs;
    static int[] month;
    static int min;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int t = Integer.parseInt(br.readLine());
        for (int test_case = 1; test_case <= t; test_case++) {
            costs = new int[4];
            month = new int[12];
            min = Integer.MAX_VALUE;

            String[] c = br.readLine().split(" ");
            String[] m = br.readLine().split(" ");

            for (int i = 0; i < c.length; i++) {
                costs[i] = Integer.parseInt(c[i]);
            }

            for (int i = 0; i < m.length; i++) {
                month[i] = Integer.parseInt(m[i]);
            }

            dfs(0, 0);
            min = Math.min(min, costs[3]); // 1년 이용권과 비교 
            sb.append("#").append(test_case).append(" ").append(min).append("\n");
        }
        System.out.println(sb);
    }

    static void dfs(int index, int ret) {
        if(index >= 12) {
            if(ret > 0)
                min = Math.min(min, ret);
            return;
        }

        if(month[index] > 0) {
            // 1일 이용권
            dfs(index + 1, ret + month[index] * costs[0]);
            // 한달 이용권
            dfs(index + 1, ret + costs[1]);
            // 세달 이용권
            dfs(index + 3, ret + costs[2]);
        } else {
            dfs(index + 1, ret);
        }
        
    }
}