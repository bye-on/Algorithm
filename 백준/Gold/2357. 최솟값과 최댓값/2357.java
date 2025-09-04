import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Iterator;
import java.util.StringTokenizer;

public class Main {
	static minmax[] tree;
	static int[] arr;
	
	static class minmax {
		int min;
		int max;
				
		public minmax(int min, int max) {
			this.min = min;
			this.max = max;
		}
	}
	
	static void init(int node, int s, int e) {
		if(s == e) {
			tree[node] = new minmax(arr[s], arr[s]);
			return;
		}
		
		int m = (s + e) / 2;
		init(node * 2, s, m);
		init(node * 2 + 1, m + 1, e);
		tree[node] = new minmax(Math.min(tree[node * 2].min, tree[node * 2 + 1].min), 
								Math.max(tree[node * 2].max, tree[node * 2 + 1].max));
	}
	
	static minmax query(int node, int qs, int qe, int ts, int te) {
		// ts, te가 범위
		if(ts > qe || qs > te) return new minmax(Integer.MAX_VALUE, 0);
		if(ts <= qs && qe <= te) return tree[node];
		
		int m = (qs + qe) / 2;
		minmax a = query(node * 2, qs, m, ts, te);
		minmax b = query(node * 2 + 1, m + 1, qe, ts, te);
		return new minmax(Math.min(a.min, b.min), Math.max(a.max, b.max));
	}
	
	public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		
		tree = new minmax[4 * N];
		arr = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			int num = Integer.parseInt(br.readLine());
			arr[i] = num;
		}
		
		init(1, 1, N);
		
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			minmax mm = query(1, 1, N, a, b);
			sb.append(mm.min).append(" ").append(mm.max).append("\n");
		}
		System.out.println(sb);		
	}
}
