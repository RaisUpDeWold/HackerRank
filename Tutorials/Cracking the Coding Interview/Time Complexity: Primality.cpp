import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int p = in.nextInt();
        for(int a0 = 0; a0 < p; a0++){
            int n = in.nextInt();
            System.out.println(isPrime(n) ? "Prime" : "Not prime");
        }
    }
    
    public static boolean isPrime(int n) {
        if (n < 2) {
            return false;
        } else if (n == 2) {     // account for even numbers now, so that we can do i+=2 in loop below
            return true;
        } else if (n % 2 == 0) { // account for even numbers now, so that we can do i+=2 in loop below
            return false;
        }
        int sqrt = (int) Math.sqrt(n);
        for (int i = 3; i <= sqrt; i += 2) { // skips even numbers for faster results
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}
