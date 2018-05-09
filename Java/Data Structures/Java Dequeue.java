import java.util.*;
public class test {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        HashMap<Integer, Integer> map = new HashMap<>();
        ArrayDeque<Integer> deque = new ArrayDeque<Integer>();
        int n = in.nextInt();
        int m = in.nextInt();
        int max = 0;

        for (int i = 0; i < n; i++) {
            /* Remove old value (if necessary) */
            if (i >= m) {
                int old = deque.removeFirst();
                if (map.get(old) == 1) {
                    map.remove(old);
                } else {
                    map.merge(old, -1, Integer::sum);
                }
            }
            
            /* Add new value */
            int num = in.nextInt();
            deque.addLast(num);
            map.merge(num, 1, Integer::sum);
        
            max = Math.max(max, map.size());
        }
        
        in.close();
        System.out.println(max);
    }
}
