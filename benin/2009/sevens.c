#include <stdio.h>
#include <ctype.h>

/* Decimal codes for digits. */
/* Code for digit `d` is at index d, i.e. code for digit 7 is at index 7. */
int  codes[] = { 63, 10, 93, 79, 106, 103, 119, 11, 127, 107 };

/**
 * Returns the digit which corresponds to a given code.
 */
int digitFor(int code)
{
    int d = -1;

    for (int i = 0; i < 10 && d == -1; ++i) {
        if (codes[i] == code) {
            d = i;
        }
    }

    return d;
}

/**
 * Convert a display code to a decimal number.
 */
int getNumber(char *displayCode)
{
    char *p;
    int   code, number;

    number = 0;
    p = displayCode;
    while(sscanf(p, "%3d", &code) > 0) {
        number = number * 10 + digitFor(code);
        p += 3;
    }
    fprintf(stderr, "getNumber(%s) => %d\n", displayCode, number);

    return number;
}

/**
 * Builds the display code for a given number.
 */
void getDisplayCode(int number, char *out)
{
    char buffer[11];
    char ch;
    int  i;

    sprintf(buffer, "%d", number);
    i = 0;
    while (buffer[i] != '\0') {
        ch = buffer[i];
        sprintf(out, "%03d", codes[ch - '0']);
        out += 3;
        ++i;
    }
   *out = '\0';
}

int main()
{
    char a[31], b[31], c[31];
    int  x, y;
 
    while (scanf("%[0-9]+%[0-9]=\n", a, b) == 2) {
        x = getNumber(a);
        y = getNumber(b);
        getDisplayCode(x + y, c);
        printf("%s+%s=%s\n", a, b, c);
    }

    return 0;
}

