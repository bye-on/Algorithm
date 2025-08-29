import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

public class Solution {
	static int[] dx = {-1, 0, 1, 0};
	static int[] dy = {0, -1, 0, 1};
	
	static int N, W, H;
	static int min;
	
	static class pos {
		int x;
		int y;
		int cnt;
		
		public pos(int x, int y, int cnt) {
			this.x = x;
			this.y = y;
			this.cnt = cnt;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			String[] str = br.readLine().split(" ");
			N = Integer.parseInt(str[0]);
			W = Integer.parseInt(str[1]);
			H = Integer.parseInt(str[2]);
			
			int[][] map = new int[H][W];
			for (int i = 0; i < H; i++) {
				String[] input = br.readLine().split(" ");
				for (int j = 0; j < W; j++) {
					int num = Integer.parseInt(input[j]);
					map[i][j] = num;
				}
			}
			
			min = Integer.MAX_VALUE;
			dropCircle(0, map);			
			
			sb.append("#").append(test_case).append(" ").append(min).append("\n");
		}
		System.out.println(sb);
	}
	
	static int getRemain(int[][] map) {
		int result = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if(map[i][j] > 0)
					result++;
			}
		}
		
		return result;
	}
	
	public static boolean dropCircle(int cnt, int[][] map) {
		int remain = getRemain(map);
		
		if(remain == 0) {
			min = 0;
			return true;
		}
		
		if(cnt == N) {
			min = Math.min(min, remain);
			return false;
		}
		
		int[][] tmp = new int[H][W];
		for (int c = 0; c < W; c++) {
			int r = 0;
			while(r < H && map[r][c] == 0) ++r;
			if(r == H) continue;
			
			copy(map, tmp);
			bomb(r, c, tmp);
			downBlock(tmp);
			if(dropCircle(cnt + 1, tmp)) return true;
		}
		
		return false;
	}
	
	public static void copy(int[][] map, int[][] tmp) {
		for (int r = 0; r < H; r++) {
			for (int c = 0; c < W; c++) {
				tmp[r][c] = map[r][c];
			}
		}
	}
	
	public static void bomb(int r, int c, int[][] map) {
		Queue<pos> q = new LinkedList<>();
		if(map[r][c] > 1) q.add(new pos(r, c, map[r][c]));
		map[r][c] = 0;
		
		while(!q.isEmpty()) {
			pos p = q.poll();
			
			for (int i = 0; i < 4; i++) {
				int nx = p.x, ny = p.y;
				
				for (int j = 1; j < p.cnt ; j++) {
					nx += dx[i];
					ny += dy[i];
					
					if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
									
					if(map[nx][ny] > 1) 
						q.add(new pos(nx, ny, map[nx][ny]));
						
					map[nx][ny] = 0;
				}
			}
		}
	}
	
	static Stack<Integer> stack = new Stack<>();
	public static void downBlock(int[][] map) {
		for (int c = 0; c < W; c++) {
			for (int r = 0; r < H; r++) {
				if(map[r][c] == 0) continue;

				stack.push(map[r][c]);
				map[r][c] = 0;
			}
			
			int r = H - 1;
			while (!stack.isEmpty()) {
				map[r--][c] = stack.pop();
			}
		}
	}
}
