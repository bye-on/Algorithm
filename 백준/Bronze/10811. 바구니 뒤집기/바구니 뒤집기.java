import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException {
		//-------여기에 해결 코드를 작성하세요.
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int[] arr = new int[N + 1];
		for (int i = 1; i <= N; i++) {
			arr[i] = i;
		}
		
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			int size = b - a + 1;
			int[] tmp = new int[size];
			for (int j = a, index = 0; j <= b; j++) {
				tmp[index++] = arr[j];
			}
			
			for (int j = a, index = size - 1; j <= b; j++) {
				arr[j] = tmp[index--];
			}
		}
		
		for (int i = 1; i <= N; i++) {
			System.out.print(arr[i] + " ");
		}
	}

}
