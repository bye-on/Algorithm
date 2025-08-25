import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			String[] str = br.readLine().split(" ");
			int n = Integer.parseInt(str[0]);
			int m = Integer.parseInt(str[1]);

			ArrayList<Integer>[] graph = new ArrayList[n + 1];
			for (int i = 0; i <= n; i++) {
				graph[i] = new ArrayList<>();
			}
			
			for (int i = 0; i < m; i++) {
				String[] input = br.readLine().split(" ");
				int a = Integer.parseInt(input[0]);
				int b = Integer.parseInt(input[1]);
				
				graph[a].add(b);
				graph[b].add(a);
			}
			
			boolean[] visited = new boolean[n + 1];
			Queue<Integer> q = new LinkedList<>();
			
			int result = 0;
			for (int i = 1; i <= n; i++) {
				if(!visited[i]) {
					q.add(i);
					result++;
					
					while(!q.isEmpty()) {
						int current = q.poll();
						
						for (int j = 0; j < graph[current].size(); j++) {
							int next = graph[current].get(j);
							if(!visited[next]) {
								visited[next] = true;
								q.add(next);
							}
						}
					}
				}
			}
			
			sb.append("#").append(test_case).append(" ").append(result).append("\n");
		}
		System.out.println(sb);
	}
}
