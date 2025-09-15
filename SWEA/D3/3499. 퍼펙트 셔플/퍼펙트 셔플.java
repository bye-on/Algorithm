import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Iterator;

public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		for (int test_case = 1; test_case <= T; test_case++) {
			int N = Integer.parseInt(br.readLine());
			String[] input = br.readLine().split(" ");
			ArrayList<String> A = new ArrayList<>();
			ArrayList<String> B = new ArrayList<>();
			
			int index = 0;
			if(N % 2 == 0) {
				for (int i = 0; i < N / 2; i++) {
					A.add(input[index++]);
				}				
			}
			else {
				for (int i = 0; i < (N / 2) + 1; i++) {
					A.add(input[index++]);
				}
			}
			
			for (int i = 0; i < N / 2; i++) {
				B.add(input[index++]);
			}
			
			sb.append("#").append(test_case).append(" ");
			for (int i = 0; i < N / 2; i++) {
				sb.append(A.get(i)).append(" ").append(B.get(i)).append(" ");
			}
			if(N % 2 != 0)
				sb.append(A.get(A.size() - 1));
			
			sb.append("\n");
		}
		System.out.println(sb);
	}
}
