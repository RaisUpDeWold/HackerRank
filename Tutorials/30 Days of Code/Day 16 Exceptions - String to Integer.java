import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String S = in.next();
        
        try {
			int intValue = Integer.parseInt(S);
			System.out.println(intValue);
		} catch (NumberFormatException nfe) {
			System.out.println("Bad String");
		}

		in.close();
    }
}
