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
    static boolean[] check;
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
        check = new boolean[n + 1];
        dfs(1, 0);
        if (result == 0)
            System.out.println(result);
        else
            System.out.println(result - 1);
    }

    static void dfs(int start, int depth) {
        if (depth == 2)
            return;

        if (!visited[start]) {
            visited[start] = true;

            for (int i = 0; i < graph[start].size(); i++) {
                int next = graph[start].get(i);
                // visited[next] = true;
                dfs(next, depth + 1);

                if (!check[next]) {
                    result++;
                    check[next] = true;
                }
            }
        }
    }
}
