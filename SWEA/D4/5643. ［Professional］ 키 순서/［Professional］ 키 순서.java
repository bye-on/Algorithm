import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
	static boolean[] visited;
	static int N;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			N = Integer.parseInt(br.readLine());
			int M = Integer.parseInt(br.readLine());
			
			ArrayList<Integer>[] order = new ArrayList[N + 1];
			ArrayList<Integer>[] reorder = new ArrayList[N + 1];
			
			for (int i = 0; i <= N; i++) {
				order[i] = new ArrayList<>();
				reorder[i] = new ArrayList<>();
			}

			for (int i = 0; i < M; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				
				order[a].add(b);
				reorder[b].add(a);
			}
			
			int result = 0;
			for (int i = 1; i <= N; i++) {
				visited = new boolean[N + 1];
				bfs(order, i);
				bfs(reorder, i);
				
				if(check())
					result++;
			}
			
			sb.append("#").append(test_case).append(" ").append(result).append("\n");
		}
		System.out.println(sb);
	}
	
	public static boolean check() {
		for (int i = 1; i <= N; i++) {
			if(!visited[i])
				return false;
		}
		
		return true;
	}
	
	public static void bfs(ArrayList<Integer>[] graph, int start) {
		Queue<Integer> q = new ArrayDeque<>();
		q.add(start);
		
		while(!q.isEmpty()) {
			int current = q.poll();
			visited[current] = true;
			
			for (int i = 0; i < graph[current].size(); i++) {
				int next = graph[current].get(i);
				
				if(!visited[next]) {					
					q.add(next);
					visited[next] = true;
				}
			}
		}
	}
}
