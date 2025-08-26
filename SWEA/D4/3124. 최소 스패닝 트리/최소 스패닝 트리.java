import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Solution {
	static int[] parent;
	
	public static int findParent(int x) {
		if(parent[x] == x)
			return parent[x];
		return parent[x] = findParent(parent[x]);
	}
	
	public static void unionParent(int a, int b) {
		a = findParent(a);
		b = findParent(b);
		
		if(a < b)
			parent[b] = a;
		else
			parent[a] = b;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			String[] ve = br.readLine().split(" ");
			int v = Integer.parseInt(ve[0]);
			int e = Integer.parseInt(ve[1]);
			
			parent = new int[v + 1];
			for (int i = 0; i <= v; i++) {
				parent[i] = i;
			}
			
			PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
				@Override
				public int compare(int[] o1, int[] o2) {
					// TODO Auto-generated method stub
					return o1[2] - o2[2];
				}
			});
			
			for (int i = 0; i < e; i++) {
				String[] input = br.readLine().split(" ");
				int a = Integer.parseInt(input[0]);
				int b = Integer.parseInt(input[1]);
				int c = Integer.parseInt(input[2]);

				pq.add(new int[] {a, b, c});
			}

			long result = 0;
			while(!pq.isEmpty()) {
				int[] node = pq.poll();
				int x = node[0];
				int y = node[1];
				int cost = node[2];
				
				if(findParent(x) != findParent(y)) {
					unionParent(x, y);
					result += cost;
				}
			}
			
			sb.append("#").append(test_case).append(" ").append(result).append("\n");
		}
		System.out.println(sb);
	}
}
