import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Solution {
    static int[] A;
    static int[] B;
    static boolean[] visited;
    static long resultA;
    static long resultB;

    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int test_case = 1; test_case <= T; test_case++) {
            A = new int[9];
            B = new int[9];
            visited = new boolean[19];
            resultA = 0;
            resultB = 0;

            String[] str = br.readLine().split(" ");
            for (int i = 0; i < str.length; i++) {
                int n = Integer.parseInt(str[i]);

                A[i] = n;
                visited[n] = true;
            }

            dfs(0);
            System.out.println("#"+ test_case + " " + resultA + " " + resultB);
        }
    }

    static void dfs(int depth) {
        if (depth == 9) {
            int a = 0;
            int b = 0;

            for (int i = 0; i < A.length; i++) {
                if (A[i] < B[i]) {
                    b += A[i];
                    b += B[i];
                }
                else if(A[i] > B[i]) {
                    a += A[i];
                    a += B[i];
                }
            }

            if (a > b)
                resultA++;
            else if (a < b)
                resultB++;

            return;
        }

        for (int i = 1; i <= 18; i++) {
            if (!visited[i]) {
                visited[i] = true;
                B[depth] = i;
                dfs(depth + 1);
                visited[i] = false;
            }
        }
    }
}