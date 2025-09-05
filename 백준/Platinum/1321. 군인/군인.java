import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int[] tree;
	static int[] arr;
	
	static int N;
	
	static void update(int i, int diff) {
		while(i <= N) {
			tree[i] += diff;
			i += (i & -i);
		}
	}
	
	static int sum(int i) {
		int result = 0;
		while(i > 0) {
			result += tree[i];
			i -= (i & -i);
		}
		
		return result;
	}
	
	// k번째 원소 찾기 (펜윅트리 이진 탐색)
	static int findKth(int k) {
	    int idx = 0;
	    int bit = 1;
	    while (bit <= N) bit <<= 1; // 가장 큰 2^x 찾기
	    for (int step = bit; step > 0; step >>= 1) {
	        if (idx + step <= N && tree[idx + step] < k) {
	            k -= tree[idx + step];
	            idx += step;
	        }
	    }
	    return idx + 1;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		N = Integer.parseInt(br.readLine());
		tree = new int[N + 1];
		arr = new int[N + 1];

		StringTokenizer st = new StringTokenizer(br.readLine());
		for (int i = 1; i < N + 1; i++) {
			int num = Integer.parseInt(st.nextToken());
			arr[i] = num;
		}
		
		for (int i = 1; i <= N; i++) {
			update(i, arr[i]);
		}
		
		int M = Integer.parseInt(br.readLine());
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			
			if(a == 1) {
				int b = Integer.parseInt(st.nextToken());
				int c = Integer.parseInt(st.nextToken());

				update(b, c);
			} else if(a == 2) {
				int b = Integer.parseInt(st.nextToken());
			    sb.append(findKth(b)).append("\n");
			}
		}
		System.out.println(sb);
	}
}
