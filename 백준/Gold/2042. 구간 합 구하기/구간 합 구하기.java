import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static long[] tree;
	static long[] arr;
	
	static int N, M, K;
	
	static long sum(int i) {
		long result = 0;
		while(i > 0) {
			result += tree[i];
			i -= (i & -i);
		}
		
		return result;
	}
	
	static void update(int i, long diff) {
		while(i <= N) {
			tree[i] += diff;
			i += (i & -i);
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		tree = new long[N + 1];
		arr = new long[N + 1];
		for (int i = 0; i < N; i++) {
			long num = Long.parseLong(br.readLine());
			arr[i + 1] = num;
			update(i + 1, num);
		}
		
		for (int i = 0; i < M + K; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			if(a == 1) {
				long c = Long.parseLong(st.nextToken());
				long diff = c - arr[b];
				arr[b] = c;
				update(b, diff);
			}
			else if(a == 2) {				
				int c = Integer.parseInt(st.nextToken());
				long result = sum(c) - sum(b - 1);
				sb.append(result).append("\n");
			}
		}
		System.out.println(sb);
	}
}
