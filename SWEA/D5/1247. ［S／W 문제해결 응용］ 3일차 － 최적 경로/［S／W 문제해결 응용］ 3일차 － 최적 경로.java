import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Solution {
	
	static ArrayList<Pair<Integer, Integer>> arr;
	
	static int n;
	
	static int companyX;
	static int companyY;
	static int homeX;
	static int homeY;
	
	static int min;
	static boolean[] visited;
	
	static class Pair<K, V> {
		public final K first;
		public final V second;
		
		public Pair(K first, V second) {
			this.first = first;
			this.second = second;
		}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			n = Integer.parseInt(br.readLine());
			
			arr = new ArrayList<>();
			min = Integer.MAX_VALUE;
			String[] str = br.readLine().split(" ");
			
			companyX = Integer.parseInt(str[0]);
			companyY = Integer.parseInt(str[1]);
			homeX = Integer.parseInt(str[2]);
			homeY = Integer.parseInt(str[3]);
			
			for (int i = 4; i < str.length; i += 2) {
				int x = Integer.parseInt(str[i]);
				int y = Integer.parseInt(str[i + 1]);
				arr.add(new Pair<Integer, Integer>(x, y));
			}
			
			visited = new boolean[n + 1];
			
			for (int i = 0; i < n; i++) {
				Pair<Integer, Integer> p = arr.get(i);
				int d = Math.abs(p.first - companyX) + Math.abs(p.second - companyY);
				
				visited[i] = true;
				dfs(i, d, 1);
				visited[i] = false;
			}
			
			sb.append("#").append(test_case).append(" ").append(min).append("\n");	
		}
		System.out.println(sb);
	}
	
	public static void dfs(int index, int ret, int cnt) {
		if(cnt == n) {
			Pair<Integer, Integer> p = arr.get(index);
			int d = Math.abs(p.first - homeX) + Math.abs(p.second - homeY);
			
			min = Math.min(min, ret + d);
			return;
		}
		
		if(min <= ret)
			return;
		
		for (int i = 0; i < arr.size(); i++) {
			if(!visited[i]) {
				visited[i] = true;
				Pair<Integer, Integer> p1 = arr.get(i);
				Pair<Integer, Integer> p2 = arr.get(index);
				int d = Math.abs(p1.first - p2.first) + Math.abs(p1.second - p2.second);
				dfs(i, ret + d, cnt + 1);				
				visited[i] = false;
			}	
		}
	}
}
