import java.util.Scanner;
class Solution {
   public static int gcd ( int a, int b)
    {
    if(a==0)
        return b;
    else if(b==0)
        return a;
    else
        return gcd(b,a%b);
    }
 
    public static void main(String args[])
    {
        Scanner in = new Scanner(System.in);
        int num = in.nextInt(); 
        int a,b;
        while(num-- > 0)
        {
            a = in.nextInt();
            b = in.nextInt();
            System.out.println((a*b)/(gcd(a,b)*gcd(a,b)));
        }
    }
}
