import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class Solution {
	
	static class Pair<K, V> {
		public final K first;
		public final V second;
		
		public Pair(K first, V second) {
			this.first = first;
			this.second = second;
		}
	}
	
	static class pos implements Comparable<pos> {
		double d;
		int node;
		
		public pos(double d, int node) {
			this.d = d;
			this.node = node;
		}
		
		@Override
		public int compareTo(pos o) {
		    return Double.compare(this.d, o.d); // d 오름차순
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			int n = Integer.parseInt(br.readLine());
			
			ArrayList<Pair<Long, Long>> arr = new ArrayList<>();
			String[] xStr = br.readLine().split(" ");
			String[] yStr = br.readLine().split(" ");
			double E = Double.parseDouble(br.readLine());  
		
			for (int i = 0; i < n; i++) {
				long x = Long.parseLong(xStr[i]);
				long y = Long.parseLong(yStr[i]);
				
				arr.add(new Pair<>(x, y));
			}
			
			boolean[] visited = new boolean[n + 1];
			ArrayList<pos>[] graph = new ArrayList[n + 1];
			for (int i = 0; i <= n; i++) {
				graph[i] = new ArrayList<>();
			}
			
			for (int i = 0; i < arr.size() - 1; i++) {
				for (int j = i + 1; j < arr.size(); j++) {
					Pair<Long, Long> p1 = arr.get(i);
					Pair<Long, Long> p2 = arr.get(j);
					
					Long x1 = p1.first;
					Long y1 = p1.second;
					Long x2 = p2.first;
					Long y2 = p2.second;
					
					double d = (Math.pow((x1 - x2), 2) + Math.pow((y1 - y2), 2)) * E;
					graph[i].add(new pos(d, j));
					graph[j].add(new pos(d, i));
				}
			}
			
			PriorityQueue<pos> pq = new PriorityQueue<>();
			pq.add(new pos(0, 0));
			
			double result = 0;
			while(!pq.isEmpty()) {
				pos current = pq.poll();
				
				double d = current.d;
				int node = current.node;
				
				if(visited[node]) continue;
				
				visited[node] = true;
				result += d;
				
				for (int i = 0; i < graph[node].size(); i++) {
					pos p = graph[node].get(i);
					
					if(!visited[p.node]) {
						pq.add(new pos(p.d, p.node));
					}
				}
			}
			
			sb.append("#").append(test_case).append(" ").append(Math.round(result)).append("\n");
		}
		System.out.println(sb);
	}
}
