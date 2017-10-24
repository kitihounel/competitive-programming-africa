#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    char line[10002];
    int  counters[26], w;
    const char *delim = " \n";

    while (fgets(line, 10002, stdin) != NULL && strncmp(line, "-1", 2) != 0) {
        char *ptr = strtok(line, delim);

        w = 0;
        fill(counters, counters + 26, 0);
        while (ptr != NULL) {
            char *tmp = ptr;
            bool  letterFound = false;

            while (*tmp != '\0') {
                if (isalpha(*tmp)) {
                    int j = tolower(*tmp) - 'a';

                    ++counters[j];
                    letterFound = true;
                }
                ++tmp;
            }

            if (letterFound) {
                ++w;
            }
            ptr = strtok(NULL, delim);
        }

        printf("%d", w);
        for (int i = 0; i < 26; ++i) {
            printf(" %d", counters[i]);
        }
        printf("\n");
    }

    return 0;
}

