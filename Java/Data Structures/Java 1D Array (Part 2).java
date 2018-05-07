import java.util.*;

public class Solution {
    public static boolean canWin(int[] array, int m, int i) {
        // Return true if you can win the game; otherwise, return false.
        /* Base Cases */
        if (i < 0 || array[i] == 1) {
            return false;
        } else if (i + 1 >= array.length || i + m >= array.length) {
            return true;
        }
        
        array[i] = 1; // marks as visited

        /* Recursive Cases (Tries +m first to try to finish game quickly) */
        return canWin(array, m, i + m) || 
               canWin(array, m, i + 1) || 
               canWin(array, m, i - 1);
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int q = scan.nextInt();
        while (q-- > 0) {
            int n = scan.nextInt();
            int leap = scan.nextInt();
            
            int[] game = new int[n];
            for (int i = 0; i < n; i++) {
                game[i] = scan.nextInt();
            }

            System.out.println( (canWin(game, leap, 0)) ? "YES" : "NO" );
        }
        scan.close();
    }
}
