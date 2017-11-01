/*
 * This is just a classic problem about converting numbers from one base to
 * another. However, since the numbers can be quite large, we can't use built-in
 * integer types. So we use java BigInteger class.
 *
 * Notes:
 *  + There is an error on the sample output for this problem. For the first
 *    test case (base 62 => base 2), add an extra leading `1` to the result.
 *  + Java BigInteger prints numbers in bases between 2 and 36. So, again we
 *    have make the conversion ourselves.
 *  + If both input and output bases are less than 27, you can use built-in
 *    capabilities of the BigInteger class to do the stuff, but we won't use
 *    it here.
 */
import java.math.BigInteger;
import java.util.Scanner;

import static java.lang.System.in;
import static java.lang.System.out;

public class BaseConversion {

    public static String digits = 
            "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    public static void main(String[] args) {
        int t;
        String inBase, outBase, number, result;
        BigInteger i;
        Scanner sc = new Scanner(in);

        t = sc.nextInt();
        while (t > 0) {
            inBase  = sc.next();
            outBase = sc.next();
            number  = sc.next();

            out.println(inBase  + " " + number);
            i = decimalValue(new BigInteger(inBase), number);
            result = convert(i, new BigInteger(outBase));
            out.println(outBase + " " + result);
            out.println();

            --t;
        }
    }

    /**
     * Convert a number express in an arbitary base in decimal base.
     */
    public static BigInteger decimalValue(BigInteger base, String number) {
        int d, l;
        BigInteger result = BigInteger.ZERO;

        l = number.length();
        for (int i = 0; i < l; ++i) {
            d = getDigit(number.charAt(i));
            result = result.multiply(base).add(BigInteger.valueOf((long) d));
        }

        return result;
    }

    /**
     * Get the string representation of a number expressed in decimal base in
     * an arbitrary base.
     */
    public static String convert(BigInteger number, BigInteger base) {
        StringBuilder builder = new StringBuilder(200);
        BigInteger[] a;
        int  d;
        char c;

        do {
            a = number.divideAndRemainder(base);
            d = a[1].intValue();
            c = getChar(d); // or c = digits.charAt(d);
            builder.append(c);
            number = a[0];
        } while (number.compareTo(BigInteger.ZERO) != 0);
        out.println();

        return builder.reverse().toString();
    }

    /**
     * Convert a char in its corresponding digit.
     */
    public static int getDigit(char ch) {
        if (Character.isDigit(ch)) {
            return Character.getNumericValue(ch)
                    - Character.getNumericValue('0');
        } else if (Character.isUpperCase(ch)) {
            return Character.getNumericValue(ch) + 10
                    - Character.getNumericValue('A');
        } else {
            return Character.getNumericValue(ch) + 36
                    - Character.getNumericValue('a');
        }
    }

    /**
     * Get the char corresponding to a digit. It is the reciprocal of the
     * getDigit method.
     */
    public static char getChar(int n) {
        int value;

        if (n < 10) {
            value = '0' + n;
        } else if (n < 36) {
            value = 'A' + n - 10;
        } else {
            value = 'a' + n - 36;
        }

        return ((char) value);
    }
}

