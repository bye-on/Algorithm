import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

public class Solution {
	static ArrayList<Integer>[] magnets;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		 int T = Integer.parseInt(br.readLine());
		 for (int test_case = 1; test_case <= T; test_case++) {
			int K = Integer.parseInt(br.readLine());
			
			ArrayList<Integer>[] arr = new ArrayList[5];
			for (int i = 1; i <= 4; i++) {
				arr[i] = new ArrayList<Integer>();
			}
			
			arr[1].add(2);
			arr[2].add(1);
			arr[2].add(3);
			arr[3].add(2);
			arr[3].add(4);
			arr[4].add(3);
			
			magnets = new ArrayList[6];
			for (int i = 0; i < 6; i++) {
				magnets[i] = new ArrayList<>();
			}
			
			for (int i = 0; i < 8; i++) {
				magnets[0].add(-1);
				magnets[5].add(-1);
			}
					
			for (int i = 1; i <= 4; i++) {
				String[] m = br.readLine().split(" ");
				for (int j = 0; j < 8; j++) {
					int n = Integer.parseInt(m[j]);
					magnets[i].add(n);
				}
			}
			
			for (int i = 0; i < K; i++) {
				boolean[] visited = new boolean[6];
				String[] input = br.readLine().split(" ");
				int index = Integer.parseInt(input[0]);
				int direction = Integer.parseInt(input[1]);
				
				Queue<Integer> q = new LinkedList<Integer>();
				q.add(index);
				
				while(!q.isEmpty()) {
					int current = q.poll();
					
					if(!visited[current - 1]) {
						if((magnets[current - 1].get(2) + magnets[current].get(6)) == 1) {
							visited[current - 1] = true;
							visited[current] = true;
							q.add(current - 1);
						}						
					}
					if(!visited[current + 1]) {						
						if((magnets[current].get(2) + magnets[current + 1].get(6)) == 1) {
							visited[current] = true;
							visited[current + 1] = true;
							q.add(current + 1);
						}
					}
				}
				
				Queue<int[]> lotateQ = new LinkedList<int[]>();
				lotateQ.add(new int[] {index, direction});
				
				visited[index] = true;
				while (!lotateQ.isEmpty()) {
					int[] current = lotateQ.poll();
					int idx = current[0];
					int dir = current[1];
					
					if(visited[idx]) {
						lotate(idx, dir);
					}
					
					visited[idx] = false;
					for (int j = 0; j < arr[idx].size(); j++) {
						int next = arr[idx].get(j);
						if(visited[next]) {
							lotateQ.add(new int[] {next, -dir});
						}
					}
				}
			}
			
			int result = 0;
			for (int i = 1; i <= 4; i++) {
				if(magnets[i].get(0) == 1) {					
					result += Math.pow(2, (i - 1));
				}
			}
			
			sb.append("#").append(test_case).append(" ").append(result).append("\n");
		}
		 System.out.println(sb);
	}
	
	public static void lotate(int index, int direction) {
		if(direction == 1) {
			int tmp = magnets[index].remove(7);
			magnets[index].add(0, tmp);
		}
		
		if(direction == -1) {
			int tmp = magnets[index].remove(0);
			magnets[index].add(tmp);
		}
	}
}
