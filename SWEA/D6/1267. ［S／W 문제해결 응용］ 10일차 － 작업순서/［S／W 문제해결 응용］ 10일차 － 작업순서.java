import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();

        for (int test_case = 1; test_case <= 10; test_case++) {
            String[] VE = br.readLine().split(" ");
            int V = Integer.parseInt(VE[0]);
            int E = Integer.parseInt(VE[1]);

            ArrayList<Integer>[] graph = new ArrayList[V + 1];
            for (int i = 0; i <= V; i++) {
                graph[i] = new ArrayList<>();
            }

            String[] input = br.readLine().split(" ");
            int[] indegree = new int[V + 1];
            for (int i = 0; i < 2 * E; i += 2) {
                int a = Integer.parseInt(input[i]);
                int b = Integer.parseInt(input[i + 1]);
                graph[a].add(b);
                indegree[b]++;
            }

            Queue<Integer> q = new LinkedList<>();
            for (int i = 1; i <= V; i++) {
                if(indegree[i] == 0) {
                    q.add(i);
                }
            }

            ArrayList<Integer> arr = new ArrayList<>();
            while (!q.isEmpty()) {
                int current = q.poll();
                arr.add(current);

                for (int i = 0; i < graph[current].size(); i++) {
                    int next = graph[current].get(i);
                    indegree[next]--;

                    if(indegree[next] == 0)
                        q.add(next);
                }
            }

            sb.append("#").append(test_case).append(" ");
            for (int i = 0; i < arr.size(); i++) {
                sb.append(arr.get(i)).append(" ");
            }
            sb.append("\n");
        }

        System.out.println(sb);
    }
}
