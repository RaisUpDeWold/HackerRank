import java.io.*;
import java.util.*;
public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String s = scan.nextLine();
        // Write your code here.
        String[] a = s.trim().split("[ !,?\\._'@]+",0);
		if(a.length==1&&a[0].equals("")){
			System.out.println(0);
		}else{
			System.out.println(a.length);
			for(String aa:a)System.out.println(aa);
		}
        scan.close();
    }
}
