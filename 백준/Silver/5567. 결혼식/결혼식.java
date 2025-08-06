import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

public class Main {

    static ArrayList<Integer>[] graph;
    static boolean[] visited;
    static int result;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        graph = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            String[] input = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);

            graph[a].add(b);
            graph[b].add(a);
        }

        for (int i = 0; i <= n; i++) {
            Collections.sort(graph[i]);
        }

        result = 0;
        visited = new boolean[n + 1];
        bfs(1);
        System.out.println(result);
    }

    static void bfs(int start) {
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[] { start, 0 });

        while (!q.isEmpty()) {
            int[] current = q.poll();
            int node = current[0];
            int depth = current[1];

            visited[node] = true;

            if (depth == 2)
                break;

            for (int i = 0; i < graph[node].size(); i++) {
                int next = graph[node].get(i);

                if (!visited[next]) {
                    q.add(new int[] { next, depth + 1 });
                    visited[next] = true;
                    result++;
                }
            }
        }
    }
}
