/**
 * If you want to learn more about the Lights Out puzzle, you can consult the
 * following pages:
 *   en.wikipedia.org/wiki/Lights_Out_(game)
 *   gaming.stackexchange.com/questions/11123/strategy-for-solving-lights-out-puzzle
 *   keithschwarz.com/interesting/code/?dir=lights-out
 * Altough the solution implemented here use the "light chase" method mentioned
 * in the stackexchange discussion, the arithmetic used is "stolen" from the
 * code by Keith Schwarz.
 * You should also consult keithschwarz.com. It contains a lot of interesting
 * stuffs. 
 */
#include <stdio.h>
#include <string.h>

#define HEIGHT 5
#define WIDTH  6

typedef struct light {
    int i, j;
} LIGHT;

typedef int PUZZLE[HEIGHT][WIDTH];

/**
 * Read a puzzle from stdin and return the number of lights turned on.
 */
int readPuzzle(PUZZLE p)
{
    int c = 0;

    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            scanf("%d", &p[i][j]);
            c += p[i][j];
        }
    }

    return c;
}

/**
 * Print a puzzle on stdout.
 */
void printPuzzle(PUZZLE p)
{
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            printf("%d%s", p[i][j], (j != WIDTH - 1 ? " " : "\n"));
        }
    }
}

/**
 * Check if all lights on a puzzle are turned off.
 * Returns 1 if all lights are turned off, 0 otherwise.
 */
int checkPuzzle(PUZZLE p)
{
    int b = 1;

    for (int i = 0; i < HEIGHT && b; ++i) {
        for (int j = 0; j < WIDTH && b; ++j) {
            b = (p[i][j] == 0);
        }
    }

    return b;
}

/**
 * Push a given light on a puzzle.
 * The state of the light and its neighbors are toggled.
 */
void push(PUZZLE p, LIGHT l)
{
    LIGHT neighbors[] = {
        { i: l.i - 1, j: l.j },     { i: l.i + 1, j: l.j },
        { i: l.i,     j: l.j - 1 }, { i: l.i,     j: l.j + 1 }
    };

    p[l.i][l.j] = 1 - p[l.i][l.j];
    for (int i  = 0; i < 4; ++i) {
        LIGHT n = neighbors[i];
        if (n.i >= 0 && n.i < HEIGHT && n.j >= 0 && n.j < WIDTH) {
            p[n.i][n.j] = 1 - p[n.i][n.j];
        }
    }
}

/**
 * Push a set of lights on a puzzle.
 * If an element of the array `actions` is set to 1, the corresponding light is
 * pushed on the puzzle.
 */
void pushLights(PUZZLE p, PUZZLE actions)
{
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (actions[i][j] == 1) {
                push(p, (LIGHT) {i: i, j: j});
            }
        }
    }
}

/**
 * Light chase on a given puzzle.
 * if a light in pushed during the process, the corresponding element in the
 * `actions` array is set to 1.
 */
void lightChase(PUZZLE p, PUZZLE actions)
{
    for (int i = 0; i < HEIGHT - 1; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (p[i][j] == 1) {
                actions[i + 1][j] = 1;
                push(p, (LIGHT) {i: i + 1, j: j});
            }
        }
    }
}

/**
 * Solve a given puzzle by using the light chasing method.
 * The lights to push are set to 1 in the array `actions`.
 */
void solvePuzzle(PUZZLE p, PUZZLE actions)
{
    int state; // Used to detect light(s) to press on the puzzle's first row.
    PUZZLE nextActions; // Lights to press in the 2nd round of light-chasing.

    memset(nextActions, 0, sizeof(PUZZLE));
    state = 1;
    lightChase(p, actions);
    while (!checkPuzzle(p) && state < 64) {
        pushLights(p, nextActions); // Cancel previous actions, if any.
        memset(nextActions, 0, sizeof(PUZZLE));
        for (int bit = 0; bit < WIDTH; ++bit) {
            if (state & (1 << bit)) {
                nextActions[0][bit] = 1;
                push(p, (LIGHT) {i: 0, j: bit});
            }
        }
        lightChase(p, nextActions);
        ++state;
    }
    // Format the array `actions` to match the output format.
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            actions[i][j] = (actions[i][j] + nextActions[i][j]) % 2;
        }
    }
}

int main()
{
    int  n, c;
    PUZZLE p, actions;

    scanf("%d\n", &n);
    for (int t = 0; t < n; ++t) {
        memset(actions, 0, sizeof(PUZZLE));
        if(readPuzzle(p)) {
            solvePuzzle(p, actions);
        }
        printf("PUZZLE #%d\n", t + 1);
        printPuzzle(actions);
    }

    return 0;
}
