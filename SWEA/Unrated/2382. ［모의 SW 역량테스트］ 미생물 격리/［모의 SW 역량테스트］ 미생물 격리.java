import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Solution {
	// 상 하 좌 우
	static int[] dx = { -1, 1, 0, 0 }; 
	static int[] dy = { 0, 0, -1, 1 };
	
	static class Info {
		int id;
		int x;
		int y;
		int total;
		int direction;
		
		public Info(int id, int x, int y, int total, int direction) {
			this.id = id;
			this.x = x;
			this.y = y;
			this.total = total;
			this.direction = direction;
		}
	}
	
	static Map<Integer, Info> map;
	static ArrayList<Info>[][] arr;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			String[] str = br.readLine().split(" ");
			int N = Integer.parseInt(str[0]);
			int M = Integer.parseInt(str[1]);
			int K = Integer.parseInt(str[2]);
			
			map = new HashMap<Integer, Info>();
			arr = new ArrayList[N + 2][N + 2];
			
			for (int i = 0; i < N + 2; i++) {
				for (int j = 0; j < N + 2; j++) {
					arr[i][j] = new ArrayList<>();
				}
			}
			

			for (int i = 0; i < K; i++) {
				String[] input = br.readLine().split(" ");
				int a = Integer.parseInt(input[0]);
				int b = Integer.parseInt(input[1]);
				int c = Integer.parseInt(input[2]);
				int d = Integer.parseInt(input[3]);
				
				map.put(i, new Info(i, a, b, c, d - 1));
				arr[a][b].add(new Info(i, a, b, c, d - 1));
			}
			
			for (int i = 0; i < M; i++) {
				for (int j = 0; j < K; j++) {					
					if(map.containsKey(j)) {
						Info info = map.get(j);
						
						int x = info.x;
						int y = info.y;
						int total = info.total;
						int direction = info.direction;

						int nx = x + dx[direction];
						int ny = y + dy[direction];
						
						if(nx <= 0 || nx >= N - 1 || ny <= 0 || ny >= N - 1) {
							total = (int) total / 2;
							if(total == 0) {
								map.remove(j);
								arr[x][y].remove(0);
							}
							else {
								if(direction == 0)
									direction = 1;
								else if(direction == 1)
									direction = 0;
								else if(direction == 2)
									direction = 3;
								else if(direction == 3)
									direction = 2;
								
								map.put(j, new Info(j, nx, ny, total, direction));
								arr[x][y].remove(0);
								arr[nx][ny].add(new Info(j, nx, ny, total, direction));
							}
						} else {
							map.put(j, new Info(j, nx, ny, total, direction));
							arr[x][y].remove(0);
							arr[nx][ny].add(new Info(j, nx, ny, total, direction));
						}
					}
					
				}
				
				for (int x = 0; x < N + 2; x++) {
					for (int y = 0; y < N + 2; y++) {
						if(arr[x][y].size() > 1) {
							int total = 0;
							int maxTotal = 0;
							int direction = 0;
							int id = 0;
							
							for (int j = arr[x][y].size() - 1; j >= 0; j--) {
								Info info = arr[x][y].get(j);
								
								if(maxTotal < info.total) {
									maxTotal = info.total;
									direction = info.direction;
									id = info.id;
								}
								
								total += info.total;
								map.remove(info.id);
								arr[x][y].remove(j);
							}
							
							map.put(id, new Info(id, x, y, total, direction));
							arr[x][y].add(new Info(id, x, y, total, direction));
						}
					}
				}		
			}
			
			int result = 0;
			for (int i = 0; i < K; i++) {
				if(map.containsKey(i)) {
					result += map.get(i).total;
				}
			}
			
			sb.append("#").append(test_case).append(" ").append(result).append("\n");
		}
		System.out.println(sb);
	}
}
