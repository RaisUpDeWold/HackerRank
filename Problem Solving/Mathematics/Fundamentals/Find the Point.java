import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        
        while(n-- > 0) {
            int pX = scan.nextInt();
            int pY = scan.nextInt();
            int qX = scan.nextInt();
            int qY = scan.nextInt();
            System.out.println(((2 * qX) - pX) + " " + ((2 * qY) - pY));
        }
        
        scan.close();     
    }
}
