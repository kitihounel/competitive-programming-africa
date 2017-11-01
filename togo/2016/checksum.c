#include <stdio.h>
#include <ctype.h>

int main()
{
    char packet[256];
    int  i, sum;
    
    while (scanf("%[A-M N-Z]\n", packet) > 0 && packet[0] != '#') {
        i = sum = 0;
        while (packet[i] != '\0') {
            if (isupper(packet[i])) {
                sum += (i + 1) * (packet[i] - 'A' + 1);
            }
            ++i;
        }
        printf("%d\n", sum);
    }

    return 0;
}

