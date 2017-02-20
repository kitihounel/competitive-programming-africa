/**
 * No explaination given for this problem :)
 * The only tricky thing in this problem is the sorting algorithm. Teams should
 * be sorted in descending order of solved problems, ascending order of time
 * penality and ascending order of team number.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct team {
    int number, problemCount, timePenality;
    int submissions[8];
} TEAM;

/**
 * Sorting function used by qsort.
 */
int compare(const void *a, const void *b)
{
    const TEAM *t = (TEAM *) a;
    const TEAM *u = (TEAM *) b;
    int   cmp;

    if (t->problemCount != u->problemCount) {
         cmp = u->problemCount - t->problemCount;
    } else if (t->timePenality != u->timePenality) {
         cmp =  t->timePenality - u->timePenality;
    } else {
         cmp = t->number - u->number;
    }

    return cmp;
}

/**
 * Function used to determine if two teams are tied.
 */
bool tied(const TEAM *t, const TEAM *u)
{
    return (t->problemCount == u->problemCount)
            && (t->timePenality == u->timePenality);
}

int main()
{
    int   n, t;
    int   teamNumber,   submissionTime, problemNumber;
    char  judgement[4], line[15];
    TEAM  teams[99];

    t = 0;
    while (scanf("%d\n", &n) > 0 && n != 0) {
        /* Data about runs should be reinitialized for each test case. */
        for (int i = 0; i < n; ++i) {
            teams[i].number = i + 1;
            teams[i].problemCount = 0;
            teams[i].timePenality = 0;
            memset(teams[i].submissions, 0, 8 * sizeof(int));
        }

        /* Get data about submissions made by teams. */
        fgets(line, 15, stdin);
        while (sscanf(line, "%d %d %d %s\n", &submissionTime, &teamNumber,
                                             &problemNumber, judgement) == 4) {
            TEAM *currentTeam =  &teams[teamNumber - 1];
            if (judgement[0] == 'o') {
                /* Accepted submission. */
                currentTeam->problemCount += 1;
                currentTeam->timePenality += submissionTime
                        + currentTeam->submissions[problemNumber - 1] * 20;
            } else {
                /* Rejected submission. */
                currentTeam->submissions[problemNumber - 1] += 1;
            }
            fgets(line, 15, stdin);
        }

        qsort(teams, n, sizeof(TEAM), compare);

        int i;          // Used to run through the team array.
        int best;       // Index of the current best team in the array.
        int rank;       // Current rank { 1, 2, 3 }.
        int tieCount;   // Number of tied teams at the current rank.
        
        printf("Cas #%d:\n", ++t);
        printf("No. Equipe  Rang  Problemes resolus  Temps consomme\n");
        
        i    = 0;
        best = 0;
        rank = 1;
        while (rank <= 3) {
            tieCount = 0;
            while (i < n && tied(&teams[i], &teams[best])) {
                printf("%10d %5d %18d %15d\n", teams[i].number, rank,
                                teams[i].problemCount, teams[i].timePenality);
                ++tieCount;
                ++i;
            }
            rank += tieCount;
            best += tieCount;
        }
    }


    return 0;
}

