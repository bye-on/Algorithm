import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {
	
	static int[] parent;
	
	static int findParent(int x) {
		if(parent[x] == x)
			return parent[x];
		
		return parent[x] = findParent(parent[x]);
	}
	
	static void unionParent(int a, int b) {
		a = findParent(a);
		b = findParent(b);
		
		if(a < b)
			parent[b] = a;
		else
			parent[a] = b;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		int T = Integer.parseInt(br.readLine()); 
		
		for (int test_case = 1; test_case <= T; test_case++) {
			String[] str = br.readLine().split(" ");
			int n = Integer.parseInt(str[0]);
			int m = Integer.parseInt(str[1]);
			
			parent = new int[n + 1];
			for (int i = 0; i <= n; i++) {
				parent[i] = i;
			}
			
			sb.append("#").append(test_case).append(" ");
			for (int i = 0; i < m; i++) {
				String[] input = br.readLine().split(" ");
				int command = Integer.parseInt(input[0]);
				int a = Integer.parseInt(input[1]);
				int b = Integer.parseInt(input[2]);
				
				if(command == 0) {
					unionParent(a, b);
				}
				else if(command == 1) {
					if(findParent(a) != findParent(b))
						sb.append(0);
					else
						sb.append(1);
				}
			}
			sb.append("\n");
		}
		
		System.out.println(sb);
	}
}
