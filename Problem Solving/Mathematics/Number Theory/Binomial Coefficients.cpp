import java.math.BigInteger;
import java.util.Scanner;

public class Solve {

public
  static void main(String[] args) {
    Scanner input = new Scanner(System.in);
    int t = input.nextInt();
    for (; t > 0; t--) {
      BigInteger n = input.nextBigInteger();
      BigInteger p = input.nextBigInteger();

      if (n.equals(BigInteger.ZERO) || n.equals(BigInteger.ONE)) {
        System.out.println(0);
        continue;
      }

      BigInteger temp = n;
      BigInteger d = BigInteger.ONE;
      while (!temp.equals(BigInteger.ZERO)) {
        d = d.multiply(temp.mod(p).add(BigInteger.ONE));
        temp = temp.divide(p);
      }

      System.out.println(n.add(BigInteger.ONE).subtract(d));
    }
  }
}
