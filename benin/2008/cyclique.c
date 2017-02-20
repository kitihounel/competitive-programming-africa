/**
 * Since the input numbers can be large, we can not use built-in integer types.
 * So we compute multiples of an input number using long-multiplication.
 * The solution is then to compute successive multiple of the input number and
 * to check if they are rotations of the input number.
 * There is a well-known trick to know if two sequences are rotation of each
 * other. If a sequence A is a rotation of another sequence B, then A is a
 * subsequence of BB.
 * Example:
 *       A = {1, 2, 3}
 *       B = {3, 1, 2}
 *      BB = {3, 1, 2, 3, 1, 2}
 *
 * Notes:
 * 1. We do not use multiplication to compute the multiples of the input number.
 *    Since we want successive multiples, can can simply use addition.
 *    However, we provide a function that can be used to compute multiples of
 *    a given number. The code of the function is based on the one used here:
 *    http://www.geeksforgeeks.org/factorial-large-number/.
 * 
 * 2. For more information cyclic numbers, read the wikipedia article:
 *    https://en.wikipedia.org/wiki/Cyclic_number
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Compute `a` * `n` and store the result in `out`.
 * There is no bound check. `out` should be large enough to store the
 * result of the operation.
 *
 * Since the code is inspired on the one from geeksforgeeks, you should read
 * the article before diving in this code. 
 */
void multiply(int n, const char a[], char out[])
{
    int  carry, digit;
    int  i, l, p;
    char ch;

    l = strlen(a) - 1;
    i = carry = 0;
    while (l >= 0) {
        digit = a[l] - '0';
        p = digit * n + carry;
        out[i] = p % 10 + '0';
        carry  = p / 10;
        --l;
        ++i;
    }

    while (carry > 0) {
        out[i] = (carry % 10) + '0';
        carry /= 10;
        ++i;
    }
    out[i] = '\0';

    /* Now put the digits in right order by reversing the result. */
    for (int j = 0; j < i / 2; ++j) {
        ch = out[j];
        out[j] = out[i - 1 - j];
        out[i - 1 - j] = ch;
    }
}

/**
 * Compute the sum of two numbers stored in the strings `a` and `b`.
 * The result of the addition is put in `sum`.
 */
void add(const char a[], const char b[], char sum[])
{
    int  i, j;
    int  l, m, middle;
    int  carry, s;
    char ch;

    l = strlen(a) - 1;
    m = strlen(b) - 1;

    carry = i = 0;
    while (l >= 0 || m >= 0) {
        s = (l >= 0? a[l] - '0': 0) + (m >= 0? b[m] - '0': 0) + carry;
        sum[i] = (s % 10) + '0';
        carry  = s / 10;
        ++i;
        --l;
        --m;
    }

    while (carry > 0) {
        sum[i] = (carry % 10 + '0');
        carry /= 10;
        ++i;
    }
    sum[i] = '\0';
    
    /* Now put the digits in right order by reversing the result. */
    middle = i / 2;
    j = 0;
    while (j < middle) {
        ch = sum[i - 1 - j];
        sum[i - 1 - j] = sum[j];
        sum[j] = ch;
        ++j;
    }
}

int main()
{
    int  m, n;
    char haystack[121], number[61], currentMultiple[63], sum[63];
    bool cyclic;

    scanf("%d\n", &m);
    while (m > 0) {
        scanf("%s\n", number);
        haystack[0] = '\0';
        sprintf(haystack, "%s%s", number, number);

        cyclic = true;
        n = strlen(number);
        strcpy(currentMultiple, number);
        for (int i = 2; i <= n && cyclic; ++i) {
            add(currentMultiple, number, sum);
            cyclic = (strstr(haystack, sum) != NULL);
            if (cyclic) {
                strcpy(currentMultiple, sum);
            }
        }

        printf("%s %sest %scyclique\n", number, (cyclic? "": "n'"), (cyclic? "": "pas "));
        --m;
    }
}

