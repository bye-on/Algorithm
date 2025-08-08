import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Main {
    static int n;
    static int max = 0;
    static int[] d;
    static ArrayList<Integer>[] graph;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        String[] str = br.readLine().split(" ");

        n = Integer.parseInt(str[0]);
        int m = Integer.parseInt(str[1]);

        graph = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }

        for (int i = 0; i < m; i++) {
            String[] input = br.readLine().split(" ");
            int a = Integer.parseInt(input[0]);
            int b = Integer.parseInt(input[1]);

            graph[a].add(b);
        }

        d = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            visited = new boolean[n + 1];

            Queue<Integer> q = new LinkedList<>();
            q.add(i);

            visited[i] = true;

            while (!q.isEmpty()) {
                int current = q.poll();
                visited[current] = true;
                d[current]++;
                if (max < d[current])
                    max = d[current];

                for (int j = 0; j < graph[current].size(); j++) {
                    int next = graph[current].get(j);
                    if (!visited[next]) {
                        q.add(next);
                        visited[next] = true;
                    }
                }
            }
        }

        for (int i = 1; i <= n; i++) {
            if (max == d[i])
                sb.append(i).append(" ");
        }

        System.out.println(sb.toString());
    }
}
