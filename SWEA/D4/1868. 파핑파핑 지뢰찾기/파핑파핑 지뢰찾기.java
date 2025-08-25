import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class Solution {
	
	static int n;
	static char[][] map;
	
	static int[] dx = {-1, -1, -1, 0, 0, 1, 1, 1};
	static int[] dy = {-1, 0, 1, -1, 1, -1, 0, 1};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		for (int test_case = 1; test_case <= T; test_case++) {
			n = Integer.parseInt(br.readLine());
			map = new char[n][n];
			
			Queue<int[]> dot = new LinkedList<>();
			for (int i = 0; i < n; i++) {
				String str = br.readLine();
				for (int j = 0; j < n; j++) {
					map[i][j] = str.charAt(j);
					if(map[i][j] == '.')
						dot.add(new int[] {i, j});
				}
			}
			
			Queue<int[]> q = new LinkedList<>();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if(map[i][j] == '.') {						
						if(check(i, j))
							q.add(new int[] {i, j});
					}
				}
			}
			
			boolean[][] visited = new boolean[n][n];
			int result = 0;
			while (!q.isEmpty()) {
				int[] node = q.poll();
				int i = node[0];
				int j = node[1];
				
				if(!visited[i][j]) {
					bfs(node, visited);
					result++;
				}
			}
			
			
			while(!dot.isEmpty()) {
				int[] current = dot.poll();
				int x = current[0];
				int y = current[1];
				
				if(!visited[x][y]) {
					visited[x][y] = true;
					result++;
				}
			}
			sb.append("#").append(test_case).append(" ").append(result).append("\n");
		}
		System.out.println(sb);
	}
	
	static void bfs(int[] start, boolean[][] visited) {
		Queue<int[]> q = new LinkedList<>();
		q.add(start);
		
		while(!q.isEmpty()) {
			int[] current = q.poll();
			int x = current[0];
			int y = current[1];
			visited[x][y] = true;

			for (int i = 0; i < 8; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
				if(!visited[nx][ny] && map[nx][ny] == '.') {
					visited[nx][ny] = true;
					if(check(nx, ny)) {
						q.add(new int[] {nx, ny});
					}
				}
			}
		}
	}
	
	static boolean check(int i, int j) {
		for(int d = 0; d < 8; d++) {
			int nx = i + dx[d];
			int ny = j + dy[d];
			
			if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if(map[nx][ny] == '*')
				return false;
		}
		
		return true;
	}
}
