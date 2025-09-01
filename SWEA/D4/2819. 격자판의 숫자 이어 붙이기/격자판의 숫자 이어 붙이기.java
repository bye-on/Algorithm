import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;

public class Solution {
	static int[] dx = {-1, 0, 1, 0};
	static int[] dy = {0, -1, 0, 1};
	
	static int[][] map;
	static boolean[][] visited;
	static Set<String> set;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			map = new int[4][4];
			set = new HashSet<>();
			
			for (int i = 0; i < 4; i++) {
				String[] str = br.readLine().split(" ");
				for (int j = 0; j < 4; j++) {
					int n = Integer.parseInt(str[j]);
					map[i][j] = n;
				}
			}
			
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					dfs("", 0, i, j);
				}
			}
			
			sb.append("#").append(test_case).append(" ").append(set.size()).append("\n"); 
		}
		System.out.println(sb);
	}
	
	static void dfs(String ret, int depth, int r, int c) {
		if(depth == 7) {		
			set.add(ret);
			return;
		}
		
		int x = r, y = c;
		ret += map[x][y];
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
			
			dfs(ret, depth + 1, nx, ny);
		}
	}
}
