/**
 * The solution is to compute the factorial of the number, transform it into
 * a string, sort the string, remove the leading zeros, and print the remaining
 * string.
 * Since it will be costly to compute the factorial of each input number and to
 * avoid useless computations, we compute the factorial of numbers 1 through
 * 100 at the begining of the program.
 */

import java.util.Scanner;
import java.util.Arrays;
import java.math.BigInteger;

public class factoriel {

    private static BigInteger fact[];

    static {
        fact = new BigInteger[100];
        fact[0] = BigInteger.ONE;
        for (int i = 1; i < 100; ++i) {
            fact[i] = fact[i - 1].multiply(BigInteger.valueOf((long) i + 1));
        }
    }

    public static void main(String[] arg) {
        int  n, x;
        char a[];
        Scanner sc = new Scanner(System.in);
        String  s;
        
        n = sc.nextInt();
        for (int i = 0; i < n; ++i) {
            x = sc.nextInt();
            a = fact[x - 1].toString().toCharArray();
            Arrays.sort(a);
            s = new String(a);
            System.out.println(s.substring(s.lastIndexOf('0') + 1));
        }
        sc.close();
    }
}

