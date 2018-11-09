import java.util.*;
import java.io.*;
// Aditya Chatterjee 
public class solution_3
{
    public static long mod = 1000000007;
	public static void main(String args[])
	{
        Scanner sc = new Scanner(System.in);
        long num[] = new long[200002];
        num[0] = 1; num[1] = 1; num[2] = 4;
        for(int i=3;i<200002; i++)
            {
            num[i] = (((num[i-1] * i ) % mod ) * i) % mod;
        }
		int d = readInt();
		for(int i=0;i<d;i++)
		{
			int m = readInt();
			int a = readInt();
			long sol = 1;
			long div = power_mod(2, m, mod);
            sol = (num[a+m+2] * inverse_mod((int) num[a+1], mod)) % mod;
            sol = (sol * inverse_mod((int) (a+2), mod)) % mod;
            sol = (sol * inverse_mod((int) (a+m+2), mod)) % mod;
			sol = (sol * inverse_mod((int) div, mod)) % mod;
			System.out.println(sol);
		}
	}

    public static int power_mod(long n, long power, long mod) 
    {
        long result = 1, s = n;
        while (power != 0L) 
        {
            if ((power & 1L) != 0L) 
                result = (result * s) % mod;
            s = (s * s) % mod;
            power >>>= 1;
        }
        return (int)result;
    }
    
    public static int inverse_mod(int n, long mod) 
    {
        return power_mod(n, mod - 2, mod);
    }
	
    static InputStream in = new BufferedInputStream(System.in);

    static int readInt() 
    {
        try {
            int c = in.read();
            while (c <= 32) 
            {
                c = in.read();
            }
            boolean minus = false;
            if (c == '-') {
                minus = true;
                c = in.read();
            }
            int result = (c - '0');
            c = in.read();
            while (c >= '0') {
                result = result * 10 + (c - '0');
                c = in.read();
            }
            return minus ? -result : result;
        } catch (IOException e) {
            return -1; 
        }
    }

    
}
