import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;

public class Solution {
	
	// 상 하 좌 우
	static int[] dx = {-1, 1, 0, 0};
	static int[] dy = {0, 0, -1, 1};
	
	static int N, M, R, C, L;
	static int[][] map;

    static int answer;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			String[] str = br.readLine().split(" ");
			N = Integer.parseInt(str[0]);
			M = Integer.parseInt(str[1]);
			R = Integer.parseInt(str[2]);
			C = Integer.parseInt(str[3]);
			L = Integer.parseInt(str[4]);

            answer = 0;
			
			map = new int[N][M];
			for (int i = 0; i < N; i++) {
				String[] input = br.readLine().split(" ");
				for (int j = 0; j < M; j++) {
					int num = Integer.parseInt(input[j]);
					map[i][j] = num;
				}
			}

			bfs();
			sb.append("#").append(test_case).append(" ").append(answer).append("\n");
		}
		System.out.println(sb);
	}
	
	static void bfs() {
		Queue<int[]> q = new ArrayDeque<int[]>();
		
		boolean[][] visited = new boolean[N][M];
        visited[R][C] = true;
		q.add(new int[] {R, C, 1});

		answer++;

        if(L == 1)
            return;

		while(!q.isEmpty()) {
			int[] current = q.poll();
			int x = current[0];
			int y = current[1];
			int depth = current[2];
			
			if(depth == L)
				continue;
			
			int direction = map[x][y];
			
			switch (direction) {
			case 1: // 상하좌우
				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					
					if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if(!visited[nx][ny]) {
						int n = map[nx][ny];
						if(i == 0) { // 상
							if(n == 1 || n == 2 || n == 5 || n == 6) {
								visited[nx][ny] = true;
								q.add(new int[] {nx, ny, depth + 1});	
                                answer++;
							}
						}
						else if(i == 1) { // 하
							if(n == 1 || n == 2 || n == 4 || n == 7) {
								visited[nx][ny] = true;
								q.add(new int[] {nx, ny, depth + 1});	
                                answer++;
							}
						} 
                        else if(i == 2) { // 좌
							if(n == 1 || n == 3 || n == 4 || n == 5) {
								visited[nx][ny] = true;
								q.add(new int[] {nx, ny, depth + 1});	
                                answer++;
							}
						}
						else if(i == 3) { // 우
							if(n == 1 || n == 3 || n == 6 || n == 7) {
								visited[nx][ny] = true;
								q.add(new int[] {nx, ny, depth + 1});	
                                answer++;
							}
						}
					}
				}
				break;
			case 2: // 상하(현재) 
				for (int i = 0; i < 2; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					
					if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if(!visited[nx][ny]) {
						int n = map[nx][ny];
						if(i == 0) { // 상
							if(n == 1 || n == 2 || n == 5 || n == 6) {
								visited[nx][ny] = true;
								q.add(new int[] {nx, ny, depth + 1});	
                                answer++;
							}
						}
						else if(i == 1) { // 하
							if(n == 1 || n == 2 || n == 4 || n == 7) {
								visited[nx][ny] = true;
								q.add(new int[] {nx, ny, depth + 1});	
                                answer++;
							}
						}
					}
				}
				
				break;
			case 3: // 좌우
				for (int i = 2; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					
					if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if(!visited[nx][ny]) {
						int n = map[nx][ny];
						if(i == 2) { // 좌
							if(n == 1 || n == 3 || n == 4 || n == 5) {
								visited[nx][ny] = true;
								q.add(new int[] {nx, ny, depth + 1});	
                                answer++;
							}
						}
						else if(i == 3) { // 우
							if(n == 1 || n == 3 || n == 6 || n == 7) {
								visited[nx][ny] = true;
								q.add(new int[] {nx, ny, depth + 1});	
                                answer++;
							}
						}
					}
				}
				
				break;
			case 4: // 상우
				for (int i = 0; i < 4; i += 3) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					
					if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if(!visited[nx][ny]) {
						int n = map[nx][ny];
						if(i == 0) { // 상
							if(n == 1 || n == 2 || n == 5 || n == 6) {
								visited[nx][ny] = true;
								q.add(new int[] {nx, ny, depth + 1});	
                                answer++;
							}
						}
						else if(i == 3) { // 우
							if(n == 1 || n == 3 || n == 6 || n == 7) {
								visited[nx][ny] = true;
								q.add(new int[] {nx, ny, depth + 1});	
                                answer++;
							}
						}
					}
				}
				
				break;
			
			case 5: // 하우
				for (int i = 1; i < 4; i += 2) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					
					if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if(!visited[nx][ny]) {
						int n = map[nx][ny];
						if(i == 1) { // 하
							if(n == 1 || n == 2 || n == 4 || n == 7) {
								visited[nx][ny] = true;
								q.add(new int[] {nx, ny, depth + 1});	
                                answer++;
							}
						}
						else if(i == 3) { // 우
							if(n == 1 || n == 3 || n == 6 || n == 7) {
								visited[nx][ny] = true;
								q.add(new int[] {nx, ny, depth + 1});	
                                answer++;
							}
						}
					}
				}
				
				break;
			case 6: // 하좌
				for (int i = 1; i < 3; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					
					if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if(!visited[nx][ny]) {
						int n = map[nx][ny];
						if(i == 1) { // 하
							if(n == 1 || n == 2 || n == 4 || n == 7) {
								visited[nx][ny] = true;
								q.add(new int[] {nx, ny, depth + 1});	
                                answer++;
							}
						}
						else if(i == 2) { // 좌
							if(n == 1 || n == 3 || n == 4 || n == 5) {
								visited[nx][ny] = true;
								q.add(new int[] {nx, ny, depth + 1});	
                                answer++;
							}
						}
					}
				}
				
				break;
			case 7: // 상좌
				for (int i = 0; i < 4; i += 2) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					
					if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
					if(!visited[nx][ny]) {
						int n = map[nx][ny];
						if(i == 0) { // 상
							if(n == 1 || n == 2 || n == 5 || n == 6) {
								visited[nx][ny] = true;
								q.add(new int[] {nx, ny, depth + 1});	
                                answer++;
							}
						}
						else if(i == 2) { // 좌
							if(n == 1 || n == 3 || n == 4 || n == 5) {
								visited[nx][ny] = true;
								q.add(new int[] {nx, ny, depth + 1});	
                                answer++;
							}
						}
					}
				}
				
				break;

			default:
				break;
			}
		}
	}
}
