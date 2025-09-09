import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Solution {
	static int[][] map;
	static int N;
	
	// 상하좌우
	static int[] dx = {-1, 1, 0, 0}; 
	static int[] dy = {0, 0, -1, 1};
	
	static ArrayList<int[]>[] warm;
	static int max;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		for (int test_case = 1; test_case <= T; test_case++) {
			N = Integer.parseInt(br.readLine().trim());
			map = new int[N][N];
			
			
			Queue<int[]> q = new ArrayDeque<int[]>();
			warm = new ArrayList[5];
			for (int i = 0; i < 5; i++) {
				warm[i] = new ArrayList<>();
			}
			
			for (int i = 0; i < N; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine().trim());
				for (int j = 0; j < N; j++) {
					int num = Integer.parseInt(st.nextToken());
					map[i][j] = num;
					
					if(num == 0) {
						q.add(new int[] {i, j});
					}
					
					if(num >= 6) {
						warm[num - 6].add(new int[] {i, j});
					}
				}
			}
			
			max = 0;
			while (!q.isEmpty()) {
				int[] node = q.poll();
				int x = node[0];
				int y = node[1];
				
				for (int i = 0; i < 4; i++) {
					simulation(x, y, i);
				}
			}
			
			sb.append("#").append(test_case).append(" ").append(max).append("\n");
		}
		System.out.println(sb);
	}
	
	public static void simulation(int i, int j, int direction) {
		int x = i;
		int y = j;
		
		int cnt = 0;
		while(true) {
			int nx = x + dx[direction];
			int ny = y + dy[direction];	
			
			x = nx; y = ny;
			if(nx < 0 || nx >= N || ny < 0 || ny >= N) {
				cnt++;
				if(direction == 0) {
					direction = 1;
					continue;
				}
				if(direction == 1) {
					direction = 0;
					continue;
				}
				if(direction == 2) {
					direction = 3;
					continue;
				}
				if(direction == 3) {
					direction = 2;
					continue;
				}
			}
			
			if(map[nx][ny] == -1) {
				max = Math.max(max, cnt);
				break;
			}
			
			if(nx == i && ny == j) {
				max = Math.max(max, cnt);
				break;
			}

			else if(map[nx][ny] >= 1 && map[nx][ny] <= 5) {
				cnt++;
				direction = changeDir(map[nx][ny], direction);
			}
			else if(map[nx][ny] >= 6 && map[nx][ny] <= 10) {
				int[] node = changeWarm(map[nx][ny], nx, ny);
				x = node[0]; y = node[1];
			}
			
		}
	}
	
	public static int changeDir(int angle, int direction) {
		switch (angle) {
		case 1:
			if(direction == 0) // 상
				return 1;
			if(direction == 1) // 하
				return 3;
			if(direction == 2) // 좌
				return 0;				
			if(direction == 3) // 우
				return 2;
			break;
		case 2:
			if(direction == 0) // 상
				return 3;
			if(direction == 1) // 하
				return 0;
			if(direction == 2) // 좌
				return 1;				
			if(direction == 3) // 우
				return 2;
			break;
		case 3:
			if(direction == 0) // 상
				return 2;
			if(direction == 1) // 하
				return 0;
			if(direction == 2) // 좌
				return 3;				
			if(direction == 3) // 우
				return 1;
			break;
		case 4:
			if(direction == 0) // 상
				return 1;
			if(direction == 1) // 하
				return 2;
			if(direction == 2) // 좌
				return 3;				
			if(direction == 3) // 우
				return 0;
			break;
		case 5:
			if(direction == 0) // 상
				return 1;
			if(direction == 1) // 하
				return 0;
			if(direction == 2) // 좌
				return 3;				
			if(direction == 3) // 우
				return 2;
			break;
		default:
			break;
		}
		
		return direction;
	}
	
	public static int[] changeWarm(int num, int i, int j) {
		int n = num - 6;
		
		int[] p1 = warm[n].get(0);
		int[] p2 = warm[n].get(1);
		
		// FIX 4: 현재 위치가 아닌 다른 웜홀 좌표를 반환
		if (p1[0] == i && p1[1] == j) {
			return p2;
		} else {
			return p1;
		}
	}
}
