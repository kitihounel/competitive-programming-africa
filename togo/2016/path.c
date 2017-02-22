#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int   p;
    int   pathLength;
    char  startingPath[4191], returnPath[4191];
    char *currentTown;
    char *startingPathTowns[20], *returnPathTowns[20];
    bool  same;
    
    scanf("%d\n", &p);
    while (p > 0) {
        scanf("%[a-z A-Z]\n%[a-z A-Z]\n", startingPath, returnPath);

        /* Starting path construction. */
        pathLength = 0;
        currentTown = strtok(startingPath, " ");
        while (currentTown != NULL) {
            startingPathTowns[pathLength] = currentTown;
            currentTown = strtok(NULL, " ");
            ++pathLength;
        }

        /* Return path construction. */
        pathLength = 0;
        currentTown = strtok(returnPath, " ");
        while (currentTown != NULL) {
            returnPathTowns[pathLength] = currentTown;
            currentTown = strtok(NULL, " ");
            ++pathLength;
        }
        
        same = true;
        for (int i = 0; i < pathLength && same; ++i) {
            same = (strcasecmp(startingPathTowns[i], returnPathTowns[pathLength - 1 - i]) == 0);
        }
        printf("%s\n", same? "Same": "Different");

        --p;
    }
    
    return 0;
}

