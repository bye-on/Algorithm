import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.io.IOException;

public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		for (int test_case = 1; test_case <= T; test_case++) {
			int N = Integer.parseInt(br.readLine());
			int[] arr = new int[N];
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			int max = 0;
			for (int i = 0; i < N; i++) {
				int num = Integer.parseInt(st.nextToken());
				arr[i] = num;
				max = Math.max(max, num);
			}
			
			int odd = 0; // 홀수
			int even = 0; // 짝수
			for (int i = 0; i < N; i++) {
				int remain = max - arr[i];
				
				odd += (remain % 2);
				even += (remain / 2);
			}
			
			sb.append("#").append(test_case).append(" ");
			
			if(odd > even) {
				sb.append(odd * 2 - 1).append("\n");
				continue;
			}
			
			while(odd < even) {
				odd += 2;
				even--;
			}
			
			sb.append(odd + even).append("\n");
		}
		System.out.println(sb);
	}
}
