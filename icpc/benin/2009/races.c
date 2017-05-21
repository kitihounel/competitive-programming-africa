/**
 * Notes:
 * 1. The formats used to read input with scanf are ugly and difficult to read,
 *    sorry for that. It is not my fault, blame the problem's author.
 * 2. The trick to read a line from input and discard it comes from
 *    http://stackoverflow.com/questions/2799612/how-to-skip-the-first-line-when-fscanning-a-txt-file
 * 3. The problem statement does not specify the maximum number of teams and
 *    pilots, so we use 64 and 128.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pilot {
    char firstName[13], lastName[13], fullName[26];
    int  ranks[32], score;
} PILOT;

typedef struct team {
    char name[19];
    int  score;
} TEAM;

/* Global vars. */
int   points[] = { 10, 8, 6, 5, 4, 3, 2, 1 };
int   pilotCount, teamCount;
PILOT pilots[128];
TEAM  teams[64];

int getTeamIndex(const char *teamName)
{
    int index = -1;

    for (int i = 0; i < teamCount && index == -1; ++i)
        if (!strcmp(teamName, teams[i].name))
            index = i;

    return index;
}

int getPilotIndex(const char *firstName, const char *lastName)
{
    int index = -1;

    for (int i = 0; i < pilotCount && index == -1; ++i)
        if (!strcmp(firstName, pilots[i].firstName)  && !strcmp(lastName, pilots[i].lastName))
            index = i;

    return index;
}

void addTeam(const char *teamName)
{
    strcpy(teams[teamCount].name, teamName);
    teams[teamCount].score = 0;
    teamCount += 1;
}

void addPilot(const char *firstName, const char *lastName)
{
    strcpy(pilots[pilotCount].firstName, firstName);
    strcpy(pilots[pilotCount].lastName,  lastName);
    sprintf(pilots[pilotCount].fullName, "%s %s", firstName, lastName);
    for (int i = 0; i < 8; ++i)
        pilots[pilotCount].ranks[i] =  0;
    pilots[pilotCount].score        =  0;
    pilotCount += 1;
}

int compareTeams(const void *p1, const void *p2)
{
    const TEAM *t1 = (const TEAM *) p1;
    const TEAM *t2 = (const TEAM *) p2;

    return (t1->score != t2->score)? t2->score - t1->score: strcmp(t1->name, t2->name);
}

int comparePilots(const void *p1, const void *p2)
{
    const PILOT *p = (const PILOT *) p1;
    const PILOT *q = (const PILOT *) p2;
    int   i;

    if (p->score != q->score) {
        return q->score - p->score;
    } else {
        for (i = 0; i < 8; ++i)
            if (p->ranks[i] != q->ranks[i]) break;
        return i < 8 ? q->ranks[i] - p->ranks[i] :
                       strcmp(p->lastName, q->lastName) || strcmp(p->firstName, q->firstName);
    }
}

int main()
{
    int  k, n;
    char firstName[13], lastName[13], teamName[19];
    int  pilotIndex, teamIndex;

    k = 1;
    while (scanf("%d\n", &n) && n > 0) {
        pilotCount = teamCount = 0;
        for (int i = 0; i < n; ++i) {
            // We don't need the name of the Grand prix and the ranklist header.
            // To read a line from input and discard it, we use:
            // scanf("%*[^\n]\n").
            scanf("%*[^\n]\n%*[^\n]\n");
            for (int j = 0; j < 8; ++j) {
                scanf("%*d %s %s%*[ ]%[^.].\n", firstName, lastName, teamName);

                pilotIndex = getPilotIndex(firstName, lastName);
                if (pilotIndex == -1) {
                    addPilot(firstName, lastName);
                    pilotIndex = pilotCount - 1;
                }
                pilots[pilotIndex].score    += points[j];
                pilots[pilotIndex].ranks[j] += 1;

                teamIndex = getTeamIndex(teamName);
                if (teamIndex == -1) {
                    addTeam(teamName);
                    teamIndex = teamCount - 1;
                }
                teams[teamIndex].score += points[j];
            }
            // Read the line with 3 dashes and throw it away.
            scanf("%*[^\n]\n");
        }

        qsort(pilots, pilotCount, sizeof(PILOT), comparePilots);
        qsort(teams,  teamCount,  sizeof(TEAM),  compareTeams);
        printf("Season %d:\nDrivers Standing:\n", k);
        for (int i = 0; i < pilotCount; ++i)  {
            printf("%-25s%d\n", pilots[i].fullName, pilots[i].score);
        }
        printf("\nTeams Standing:\n");
        for (int i = 0; i < teamCount; ++i) {
            printf("%-25s%d\n", teams[i].name, teams[i].score);
        }
        printf("\n");

        ++k;
    }

    return 0;
}
