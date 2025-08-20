import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        for (int test_case = 1; test_case <= 10; test_case++) {
            String[] AB = br.readLine().split(" ");
            int A = Integer.parseInt(AB[0]); // case
            int B = Integer.parseInt(AB[1]); // start
    
            ArrayList<Integer>[] arr = new ArrayList[101];
    
            for (int i = 0; i < 101; i++) {
                arr[i] = new ArrayList<>();
            }
            
            String[] input = br.readLine().split(" ");
            for (int i = 0; i < A; i += 2) {
                int a = Integer.parseInt(input[i]);
                int b = Integer.parseInt(input[i + 1]);

                arr[a].add(b);
            }

            Queue<int[]> q = new LinkedList<>();
            boolean[] visited = new boolean[101];
            q.add(new int[] {0, B});

            PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
                @Override
                public int compare(int[] o1, int[] o2) {
                    if(o1[0] == o2[0])
                        return o2[1] - o1[1];
                    return o2[0] - o1[0];
                }
            });

            while (!q.isEmpty()) {
                int[] current = q.poll();
                int depth = current[0];
                int node = current[1];

                visited[node] = true;
                pq.add(new int[] {depth, node});

                for (int i = 0; i < arr[node].size(); i++) {
                    int next = arr[node].get(i);
                    if(!visited[next]) {
                        q.add(new int[] {depth + 1, next});
                        visited[next] = true;
                    }
                }
            }

            sb.append("#").append(test_case).append(" ").append(pq.poll()[1]).append("\n");
        }
        System.out.println(sb);
    }
}