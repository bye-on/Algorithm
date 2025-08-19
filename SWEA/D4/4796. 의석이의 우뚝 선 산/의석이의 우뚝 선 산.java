import java.io.IOException;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) throws IOException {
        // BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        int t = sc.nextInt();

        for (int test_case = 1; test_case <= t; test_case++) {
            int n = sc.nextInt();
            int[] arr = new int[n];

            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }        

            int upCnt = 0;
            int downCnt = 0;
            boolean down = false;

            int result = 0;
            for (int i = 0; i < n - 1; i++) {
                if(arr[i] < arr[i + 1]) {
                    if(!down) {
                        upCnt++;
                    }
                    else {
                        result += (upCnt * downCnt);
    
                        down = false;
                        upCnt = 1;
                        downCnt = 0;
                    }
                } else {
                    down = true;
                    downCnt++;
                }
            }

            if(down)
                result += (upCnt * downCnt);

            sb.append("#").append(test_case).append(" ").append(result).append("\n");
        }
        System.out.println(sb);
    }
}
