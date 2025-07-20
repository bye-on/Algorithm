import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static int[] stack;
    public static int top;
    public  static int capacity;

    public static int push(int x) {
        if(top >= capacity) return  -1;
        return stack[top++] = x;
    }
    public static int pop() {
        if(top <= 0) return -1;
        return stack[--top];
    }
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        capacity = Integer.parseInt(bf.readLine());
        int index = 1;
        stack = new int[capacity];
        top = 0;
        StringBuilder sb = new StringBuilder();
        StringBuilder sb1 = new StringBuilder();
        for(int i = 0; i < capacity; i++) {
            int num = Integer.parseInt(bf.readLine());
            if(top == 0) {
                for(; index <= num; index++) {
                    push(index);
                    sb.append("+").append("\n");
                    //System.out.println("+");
                }
                pop();
                sb.append("-").append("\n");
                //System.out.println("-");
            } else if(stack[top - 1] < num) {
                for(; index <= num; index++) {
                    push(index);
                    sb.append("+").append("\n");
                    //System.out.println("+");
                }
                pop();
                sb.append("-").append("\n");
                //System.out.println("-");
            } else if(stack[top - 1] == num) {
                pop();
                sb.append("-").append("\n");
                //System.out.println("-");
            } else {
                sb1.append("NO");
                break;
                //System.out.println("NO");
            }
        }
        if(pop() == -1) System.out.println(sb);
        else System.out.println(sb1);
    }
}