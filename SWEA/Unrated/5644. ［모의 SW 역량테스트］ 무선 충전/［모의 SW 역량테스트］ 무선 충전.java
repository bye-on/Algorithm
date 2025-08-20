import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
    static int[] dx = {0, 0, 1, 0, -1};
    static int[] dy = {0, -1, 0, 1, 0};

    static int M;
    static int N;

    static int[][] distance;

    static int[] A;
    static int[] B;

    static int ax, ay, bx, by;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        int T = Integer.parseInt(br.readLine());

        for (int test_case = 1; test_case <= T; test_case++) {
            
            String[] MA = br.readLine().split(" ");
            M = Integer.parseInt(MA[0]);
            N = Integer.parseInt(MA[1]);
            
            String[] a = br.readLine().split(" ");
            String[] b = br.readLine().split(" ");
            
            A = new int[M + 1];
            B = new int[M + 1];
            
            for (int i = 0; i < M; i++) {
                int numA = Integer.parseInt(a[i]);
                int numB = Integer.parseInt(b[i]);
                
                A[i + 1] = numA;
                B[i + 1] = numB;
            }
            
            distance = new int[N][4];
            for (int i = 0; i < N; i++) {
                String[] str = br.readLine().split(" ");
                distance[i][0] = Integer.parseInt(str[0]);
                distance[i][1] = Integer.parseInt(str[1]);
                distance[i][2] = Integer.parseInt(str[2]);
                distance[i][3] = Integer.parseInt(str[3]);
            }

            ax = ay = 1;
            bx = by = 10;
            sb.append("#").append(test_case).append(" ").append(move()).append("\n");
        }
        System.out.println(sb);
    }

    static int move() {
        int result = 0;

        for (int i = 0; i <= M; i++) {
            ax += dx[A[i]];
            ay += dy[A[i]];

            bx += dx[B[i]];
            by += dy[B[i]];

            result += getCharge();
        }

        return result;
    }

    static int calc(int c, int x, int y) {
        return Math.abs(distance[c][0] - x) + Math.abs(distance[c][1] - y) <= distance[c][2] ? distance[c][3] : 0;
    }
    
    static int getCharge() {
        int max = 0;
        for (int i = 0; i < N; i++) { // A가 선택한 충전소
            for (int j = 0; j < N; j++) { // B가 선택한 충전소
                int sum = 0;
                int a = calc(i, ax, ay);
                int b = calc(j, bx, by);

                if(i != j)
                    sum = a + b;
                else 
                    sum = Math.max(a, b);

                max = Math.max(max, sum);
            }
        }
        return max;
    }
}
