import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String T = br.readLine();
		String P = br.readLine();
		
		int[] pi = new int[P.length()];
		for (int i = 1, j = 0; i < P.length(); i++) {
			while (j > 0 && P.charAt(i) != P.charAt(j))
				j = pi[j - 1];
			
			if(P.charAt(i) == P.charAt(j))
				pi[i] = ++j;
		}	
		
		ArrayList<Integer> results = new ArrayList<>();
		for (int i = 0, j = 0; i < T.length(); i++) {			
			while(j > 0 && T.charAt(i) != P.charAt(j)) {
				j = pi[j - 1];
			}
			
			if(T.charAt(i) == P.charAt(j)) {
				if(j == P.length() - 1) {
					results.add(i - j + 1);
					j = pi[j];
				}
				else
					j++;
			}
		}
		
		System.out.println(results.size());
		for (int i = 0; i < results.size(); i++) {
			System.out.println(results.get(i));
		}
	}
}
