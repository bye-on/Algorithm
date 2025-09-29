import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int result = Integer.MAX_VALUE;

    static int[] arr;
    static int m;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        boolean[] opened = new boolean[n + 1];
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        opened[a] = opened[b] = true;

        m = Integer.parseInt(br.readLine());
        arr = new int[m];
        for (int i = 0; i < m; i++) {
            arr[i] = Integer.parseInt(br.readLine());
        }

        dfs(0, a, b, 0);
        System.out.println(result);
    }

    static void dfs(int index, int num1, int num2, int ret) {
        if(index >= m) {
            result = Math.min(ret, result);
            return;
        }

        if(result <= ret) 
            return;

        int openNum = arr[index];
        dfs(index + 1, openNum, num2, ret + Math.abs(num1 - openNum));
        dfs(index + 1, num1, openNum, ret + Math.abs(num2 - openNum));
    }
}
