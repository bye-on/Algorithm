import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
			@Override 
			public int compare(int[] a,  int[] b) {
				if(a[0] != b[0])
					return Integer.compare(a[0],b[0]);
				else
					return Integer.compare(a[1], b[1]);
			}
		});
		
		String[] str = br.readLine().split(" ");
		for (int i = 0; i < str.length; i++) {
			int input = Integer.parseInt(str[i]);
			pq.add(new int[] {input, i + 1});
		}
		
		LinkedList<Integer> arr = new LinkedList<>(); 
		while(!pq.isEmpty()) {
			int[] num = pq.poll();
			boolean in = false;
			
			int index = 0;
			int cnt = 0;
			for (int i = 0; i < arr.size(); i++) {
				if(cnt == num[0]) {						
					if(arr.get(i) > num[1]) {
						arr.add(index, num[1]);
						in = true;
						break;
					}
					else
						index++;
				}
				else {
					if(arr.get(i) > num[1]) {							
						index++;
						cnt++;
					}
					else
						index++;
				}
			}
			if(!in)
				arr.add(num[1]);
		}
		
		for(int i = 0; i < arr.size(); i++) {
			System.out.print(arr.get(i) + " ");			
		}
	}
}
