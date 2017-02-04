/**
  * To learn more about Ceasar cipher, read the following Wikipedia articles:
  *         - https://en.wikipedia.org/wiki/Caesar_cipher
  *         - https://en.wikipedia.org/wiki/ROT13
  * Usually, things would work as follow:
  *     Plain text alphabet                Cipher alphabet
  *     ABCD...XYZ              ==>        VWXYZAB...STU
  * In this problem the cipher alphabet and the plain alphabet are swapped.
  * So to solve the problem, simply apply a left shift of 5 (negative shift)
  * or a right shift of 21 (positive shift) to the cipher.
  *
  * NOTE: The first test case in the sample input/output is wrong.
  */
#include <stdio.h>
#include <ctype.h>

char rot(char c, int n)
{
    // In C and C++, a % b can give a negative value.
    // So to get a positive value, do ((a % b) + b) % b.
    int i = ((c - 'A' + n) % 26 + 26) % 26;

    return (i + 'A');
}

int main()
{
    char text[256];
    char flag[11];

    scanf("%s\n", flag);
    while(flag[0] == 'S') {
        fgets(text, 256, stdin);

        char *tmp = text;
        while (*tmp != '\0') {
            if(isalpha(*tmp)) {
                *tmp = rot(*tmp, -5); // *tmp = rot(*tmp, 21);
            }
            ++tmp;
        }
        printf("%s", text);

        scanf("%*s\n%s\n", flag);
    }

    return 0;
}
