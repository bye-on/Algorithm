import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;

public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			String[] ve = br.readLine().split(" ");
			int v = Integer.parseInt(ve[0]);
			int e = Integer.parseInt(ve[1]);
			
			PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
				@Override
				public int compare(int[] o1, int[] o2) {
					// TODO Auto-generated method stub
					return o1[1] - o2[1];
				}
			});
			
			ArrayList<int[]>[] graph = new ArrayList[v + 1];
			for (int i = 0; i <= v; i++) {
				graph[i] = new ArrayList<>();
			}
			
			for (int i = 0; i < e; i++) {
				String[] input = br.readLine().split(" ");
				int a = Integer.parseInt(input[0]);
				int b = Integer.parseInt(input[1]);
				int c = Integer.parseInt(input[2]);
				
				graph[a].add(new int[] {b, c});
				graph[b].add(new int[] {a, c});
			}
			
			boolean[] visited = new boolean[v + 1];
			pq.add(new int[] {1, 0});
			
			long result = 0;
			while(!pq.isEmpty()) {
				int[] node = pq.poll();
				int current = node[0];
				int cost = node[1];
				
				if(visited[current]) continue; 
					
				visited[current] = true;
				result += cost;
				
				for (int i = 0; i < graph[current].size(); i++) {
					int[] next = graph[current].get(i);
					if(!visited[next[0]]) {
						pq.add(new int[] {next[0], next[1]});
					}
				}
			}
			
			sb.append("#").append(test_case).append(" ").append(result).append("\n");
		}
		System.out.println(sb);
	}
}
