import java.util.*;

public class Main {

    public static int binarySearch(List<Integer> lis, int start, int end, int target) {
        while (start < end) {
            int middle = (start + end) / 2;
            if (lis.get(middle) < target)
                start = middle + 1;
            else
                end = middle;
        }
        return end;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        List<Integer> v = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            v.add(sc.nextInt());
        }

        List<Integer> lis = new ArrayList<>();
        List<Integer> path = new ArrayList<>();

        lis.add(v.get(0));
        path.add(0);

        for (int i = 1; i < n; i++) {
            int value = v.get(i);
            if (value > lis.get(lis.size() - 1)) {
                lis.add(value);
                path.add(lis.size() - 1);
            } else {
                int pos = binarySearch(lis, 0, lis.size() - 1, value);
                path.add(pos);
                lis.set(pos, value);
            }
        }

        List<Integer> result = new ArrayList<>();
        int length = lis.size() - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (path.get(i) == length) {
                result.add(v.get(i));
                length--;
            }
        }

        System.out.println(lis.size());
        Collections.sort(result);
        for (int i = 0; i < result.size(); i++) {
            System.out.print(result.get(i) + " ");
        }
    }
}
