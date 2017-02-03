#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct candidate {
    char name[1001];
    int  score;
} CANDIDATE;

/* Comparison function used to sort the candidates. Note that the candidates */
/* will be sorted in descending order. */
int compare(const void *ptr, const void *other)
{
    return ((CANDIDATE *) other)->score - ((CANDIDATE *) ptr)->score;
}

int main()
{
    CANDIDATE candidates[100];
    char name[1001];
    int  r;
    int  n, m, p;

    scanf("%d\n", &p);
    for (int t = 0; t < p; ++t) {
        scanf("%d %d\n", &n, &m);

        /* We read the names of the candidates and set all scores to zero. */
        for (int i = 0; i < n; ++i) {
            scanf("%s\n", candidates[i].name);
            candidates[i].score = 0;
        }

        /* We read the results. Note that the name of the centre of vote is */
        /* not useful.  So we does not store it. */
        for (int i = 0; i < m; ++i) {
            scanf("%s %d %*s\n", name, &r);
            int j = 0;
            /* The following just finds the index of the current candidate */
            /* in the array of candidates. */
            while (strcmp(name, candidates[j].name) != 0) {
                ++j;
            }
            candidates[j].score += r;
        }

        qsort(candidates, n, sizeof(CANDIDATE), compare);
        printf("VOTE %d: ", t + 1);
        if (n == 1 || candidates[0].score != candidates[1].score) {
            printf("THE WINNER IS %s %d\n", candidates[0].name, \
                                            candidates[0].score);
        } else {
            printf("THERE IS A DILEMMA\n");
        }
    }

    return 0;
}
