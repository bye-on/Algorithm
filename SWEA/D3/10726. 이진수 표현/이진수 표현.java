import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Iterator;

public class Solution {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuilder sb = new StringBuilder();
		
		int T = Integer.parseInt(br.readLine());
		for (int test_case = 1; test_case <= T; test_case++) {
			String[] NM = br.readLine().split(" ");
			int N = Integer.parseInt(NM[0]);
			int M = Integer.parseInt(NM[1]);
			
			boolean flag = false;
			for (int i = 0; i < N; i++) {
				if((M & (1 << i)) == 0)
					flag = true;
			}
			
			sb.append("#").append(test_case).append(" ");
			if(flag)
				sb.append("OFF\n");
			else
				sb.append("ON\n");
		}
		System.out.println(sb);
	}
}
