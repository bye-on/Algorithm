import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Solution {
    static int[] A;
    static int[] B;
    static boolean[] visited;
    static int[] arr;
    static long resultA;
    static long resultB;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for (int test_case = 1; test_case <= T; test_case++) {
            A = new int[9]; // 규영
            B = new int[9]; // 인영

            arr = new int[9]; // 9!의 결과들
            visited = new boolean[19];
            resultA = 0;
            resultB = 0;

            String[] str = br.readLine().split(" ");
            for (int i = 0; i < str.length; i++) {
                int n = Integer.parseInt(str[i]);

                A[i] = n;
                visited[n] = true;
            }

            int index = 0;
            for (int i = 1; i <= 18; i++) {
                if (!visited[i])
                    B[index++] = i;
            }

            dfs(0);
            sb.append("#").append(test_case).append(" ").append(resultA).append(" ").append(resultB).append("\n");
        }
        System.out.println(sb.toString());
    }

    static void dfs(int depth) {
        if (depth == 9) {
            int a = 0;
            int b = 0;

            for (int i = 0; i < A.length; i++) {
                if (A[i] < arr[i]) {
                    b += A[i];
                    b += arr[i];
                } else if (A[i] > arr[i]) {
                    a += A[i];
                    a += arr[i];
                }
            }

            if (a > b)
                resultA++;
            else if (a < b)
                resultB++;

            return;
        }

        for (int i = 0; i < 9; i++) {
            int num = B[i];
            
            if (!visited[num]) {
                visited[num] = true;
                arr[depth] = num;
                dfs(depth + 1);
                visited[num] = false;
            }
        }
    }
}