import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    public static int[] queue;
    public static int capacity;
    public static int front;
    public static int rear;
    public static int size;

    public static void enqueue(int x) {
        if(rear == capacity) rear = 0;
        queue[rear++] = x;
        size++;
    }
    public static int dequeue() {
        if(size <= 0) return -1;
        if(front == capacity) front = 0;
        size--;
        return queue[front++];
    }
    public static int size() {
        return size;
    }
    public static int empty() {
        if(size <= 0) return 1;
        else return 0;
    }
    public static int getFront() {
        if(size <= 0) return -1;
        else return queue[front];
    }
    public static int getRear() {
        if(size <= 0) return -1;
        else return queue[rear - 1];
    }
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        size = front = rear = 0;
        capacity = Integer.parseInt(bf.readLine());
        queue = new int[capacity];

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < capacity; i++) {
            String[] input = bf.readLine().split(" ");
            switch (input[0]) {
                case "push":
                    int num = Integer.parseInt(input[1]);
                    enqueue(num);
                    break;
                case "pop":
                    sb.append(dequeue()).append("\n");
                    //System.out.println(dequeue());
                    break;
                case "size":
                    sb.append(size()).append("\n");
                    //System.out.println(size());
                    break;
                case "empty":
                    sb.append(empty()).append("\n");
                    //System.out.println(empty());
                    break;
                case "front":
                    sb.append(getFront()).append("\n");
                    //System.out.println(getFront());
                    break;
                case "back":
                    sb.append(getRear()).append("\n");
                    //System.out.println(getRear());
                    break;
            }
        }
        System.out.println(sb);
    }
}