import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);

		int T = sc.nextInt();
		sc.nextLine();
		for (int tc = 0; tc < T; tc++) {
			String S = sc.nextLine();

            for (int i = 0; i < S.length(); i += 2) {
                System.out.print(S.charAt(i));
            }
			System.out.print(" ");
            for (int i = 1; i < S.length(); i += 2) {
                System.out.print(S.charAt(i));
            }
			System.out.println();
		}

		sc.close();
    }
}
