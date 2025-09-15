import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

// 다익스트라 코드
public class Main {

	public static void main(String[] args) throws IOException {
		//-------여기에 해결 코드를 작성하세요.
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int M = Integer.parseInt(br.readLine());
		
		ArrayList<int[]>[] graph = new ArrayList[N + 1];
		for (int i = 0; i <= N; i++) {
			graph[i] = new ArrayList<>();
		}
		
		int[] d = new int[N + 1];
		for (int i = 0; i <= N; i++) {
			d[i] = Integer.MAX_VALUE;
		}
		
		for (int i = 0; i < M; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			
			graph[a].add(new int[] {b, c});
		}
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int s = Integer.parseInt(st.nextToken());
		int e = Integer.parseInt(st.nextToken());
		PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				// TODO Auto-generated method stub
				return o1[1] - o2[1];
			}
		});
		pq.add(new int[] {s, 0});
		
		while(!pq.isEmpty()) {
			int[] current = pq.poll();
			
			int node = current[0];
			int cost = current[1];
			
			if(d[node] < cost) continue;
			for (int i = 0; i < graph[node].size(); i++) {
				int[] next = graph[node].get(i);
				int nextCost = cost + next[1];
				
				if(d[next[0]] <= nextCost) continue;
				d[next[0]] = nextCost;
				pq.add(new int[] {next[0], nextCost});
			}
		}
		
		System.out.println(d[e]);
	}

}

