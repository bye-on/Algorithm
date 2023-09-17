import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(bf.readLine());
        Deque<Integer> deque = new ArrayDeque<>();
        if(num == 1) {
            System.out.println(1);
            return;
        }
        for(int i = 1; i <= num; i++) {
            deque.addLast(i);
        }
        while(deque.size() != 1) {
            deque.removeFirst();
            deque.addLast(deque.poll());
        }
        System.out.println(deque.poll());
    }
}