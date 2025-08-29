import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;

public class Solution {
	
	static int[] dx = {-1, 0, 1, 0};
	static int[] dy = {0, -1, 0, 1};
	
	static int r, c; // 행 열
	static char[][] map;
	static int[][] devilCnt;
	static int[][] cnt;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			String[] input = br.readLine().split(" ");
			r = Integer.parseInt(input[0]);
			c = Integer.parseInt(input[1]);
			map = new char[r][c];
			
			devilCnt = new int[r][c];
			cnt = new int[r][c];
			for (int i = 0; i < r; i++) {
			    for (int j = 0; j < c; j++) {
			        devilCnt[i][j] = Integer.MAX_VALUE;
			    }
			}
			
			int[] goddess = new int[2];
			int[] suyeon = new int[2];
			ArrayList<int[]> devil = new ArrayList<>();
			
			for (int i = 0; i < r; i++) {
				String mapInfo = br.readLine();
				for (int j = 0; j < c; j++) {
					map[i][j] = mapInfo.charAt(j);
					
					if (map[i][j] == 'S') {
						suyeon[0] = i;
						suyeon[1] = j;
					}
					
					if(map[i][j] == 'D') {
						goddess[0] = i;
						goddess[1] = j;
					}
					
					if(map[i][j] == '*') {
						devil.add(new int[] {i, j, 0});
					}
				}
			}
			
			devilBFS(devil);
			bfs(suyeon);
			
			sb.append("#").append(test_case).append(" ");
			if(cnt[goddess[0]][goddess[1]] > 0)
				sb.append(cnt[goddess[0]][goddess[1]]).append("\n");
			else
				sb.append("GAME OVER").append("\n");
		}
		System.out.println(sb);
	}
	
	static void devilBFS(ArrayList<int[]> devil) {
		boolean[][] visited = new boolean[r][c];
		
		Queue<int[]> q = new ArrayDeque<>();
		
		for (int i = 0; i < devil.size(); i++) {			
			q.add(devil.get(i));
		} // 악마의 손아귀는 여러개 일 수 있음 
		
		while(!q.isEmpty()) {
			int[] pos = q.poll();
			int x = pos[0];
			int y = pos[1];
			int depth = pos[2];
			devilCnt[x][y] = depth;
			
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				
				if(!visited[nx][ny]) {
					if(map[nx][ny] == '.' || map[nx][ny] == 'S') {
						q.add(new int[] {nx, ny, depth + 1});
						visited[nx][ny] = true;
					}
				}
			}
		}
	}
	
	static void bfs(int[] suyeon) {
		boolean[][] visited = new boolean[r][c];
		Queue<int[]> q = new ArrayDeque<>();
		q.add(suyeon);
		
		int depth = 0;
		
		while(!q.isEmpty()) {
			int[] pos = q.poll();
			int x = pos[0];
			int y = pos[1];
			
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				
				if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
				
				if(!visited[nx][ny]) {					
					if(map[nx][ny] == '.') {
						cnt[nx][ny] = cnt[x][y] + 1;
						if(cnt[nx][ny] < devilCnt[nx][ny]) {
							q.add(new int[] {nx, ny});
							visited[nx][ny] = true;							
						}
					}
					
					if(map[nx][ny] == 'D') {
						cnt[nx][ny] = cnt[x][y] + 1;
						q.add(new int[] {nx, ny});
						visited[nx][ny] = true;		
					}
				}
			}
		}
	}
}
