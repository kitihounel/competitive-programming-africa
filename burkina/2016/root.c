/**
 * The digital root of a positive integer n is 9 if n is divisible by 9. Else
 * the digital root is given by n % 9.
 *
 * Note that the input numbers are very large and can have one thousand digits.
 * This fact is not mentionned in the problem statement. So the solution is
 * then to compute the sum of the digits in the number and to test if the sum
 * is divisible by 9.
 */
#include <stdio.h>

int main()
{
    int  m, root, sum;
    char number[1001];
    
    while (scanf("%s\n", number) > 0 && number[0] != '0') {
        sum = 0;
        for (int i = 0; number[i] != 0; ++i) {
            sum += number[i] - '0';
        }
        m = sum % 9;
        root = (m == 0? 9 : m);
        printf("%d\n", root);
    }

    return 0;
}

