import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;

public class Solution {
	static int[][] map;
	static int N, M, C;
	
	static int max;
	
	static class bee implements Comparable<bee>{
		int sum;
		int x;
		int y;
		
		public bee(int sum, int x, int y) {
			this.sum = sum;
			this.x = x;
			this.y = y;
		}
		
		@Override
		public int compareTo(bee o) {
			// TODO Auto-generated method stub
			return o.sum - this.sum; // 내림차순 
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine());
		
		for (int test_case = 1; test_case <= T; test_case++) {
			String[] NMC = br.readLine().split(" ");
			N = Integer.parseInt(NMC[0]);
			M = Integer.parseInt(NMC[1]);
			C = Integer.parseInt(NMC[2]);
			
			map = new int[N][N];
			for (int i = 0; i < N; i++) {
				String[] input = br.readLine().split(" ");
				for (int j = 0; j < N; j++) {
					int num = Integer.parseInt(input[j]);
					map[i][j] = num;
				}
			}
			
			PriorityQueue<bee> pq = new PriorityQueue<>();
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < (N - M + 1); j++) {
					max = 0;
					dfs(0, 0, i, j, 0);					
					pq.add(new bee(max, i, j));
				}
			}
			
			bee current = pq.poll();
			int result = current.sum;
			int preX = current.x; int preY = current.y;
			
			while(!pq.isEmpty()) {
				bee next = pq.poll();
				
				if(next.x != preX) {
					result += next.sum;
					break;
				}
				else {
					if(preY + M <= next.y || preY - M >= next.y) {
						result += next.sum;
						break;
					}
				}
			}
			
			sb.append("#").append(test_case).append(" ").append(result).append("\n");
		}
		System.out.println(sb);
	}
	
	public static void dfs(int ret, int tmp, int i, int j, int index) {
		if(index == M) {
			max = Math.max(max, ret);
			return;
		}
		
		dfs(ret, tmp, i, j, index + 1);
			
		tmp += map[i][j + index];
		if(tmp <= C) {
			ret += Math.pow(map[i][j + index], 2);
			dfs(ret, tmp, i, j, index + 1);
		}
	}
}
