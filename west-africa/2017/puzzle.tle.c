/**
 * Although the solution implemented here works, it takes too much time.
 * The algorithm implemented here tries to solve a puzzle by trying all
 * combinations of lights. Combinations are obtained by using the set bits in
 * numbers from 1 to (2^30 - 1).
 *
 * For example, this program takes 1m36s on my computer to solve the first
 * puzzle (in the sample input) which solution is given by the a number between
 * 36 * 10^6 and 37 * 10^6.
 *
 * If you really want to use this program, launch it in a terminal and go take
 * a lunch with your (boy|girl)friend. It will still be running when you will
 * come back.
 */
#include <stdio.h>
#include <stdbool.h>

#define WIDTH  6
#define HEIGHT 5

typedef struct light {
    int i, j;
} light;

bool puzzle[HEIGHT][WIDTH];

/**
 * Print the puzzle.
 */
void printPuzzle()
{
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            printf("%d%s", (int) puzzle[i][j], (j != WIDTH - 1 ? " " : "\n"));
        }
    }
}

/**
 * Check if all lights are turned off.
 * Returns true if all lights are turned off, false otherwise.
 */
bool checkPuzzle()
{
    bool ok = true;

    for (int i = 0; i < HEIGHT && ok; ++i) {
        for (int j = 0; j < WIDTH && ok; ++j) {
            ok = !puzzle[i][j];
        }
    }

    return ok;
}

/**
 * Push a light, i.e. switch the states of a given light and its neighbors.
 */
void push(light l)
{
    light neighbors[] = {
        { i: l.i - 1,    j: l.j },
        { i: l.i + 1,    j: l.j },
        { i: l.i,        j: l.j - 1 },
        { i: l.i,        j: l.j + 1 }
    };

    puzzle[l.i][l.j] = !puzzle[l.i][l.j];
    for (int i  = 0; i < 4; ++i) {
        light n = neighbors[i];
        if (n.i >= 0 && n.i < HEIGHT && n.j >= 0 && n.j < WIDTH) {
            puzzle[n.i][n.j] = !puzzle[n.i][n.j];
        }
    }
}

/**
 * Solve a puzzle by testing all possible combinations of lights on the puzzle.
 * Combinations are obtained by using the set bits in numbers from 1 to
 * (2^30 - 1).
 * This function relies on the fact that all puzzles in the input are solvable.
 * If a given puzzle is not solvable, it will run forever. But hopelly, all the
 * puzzles in the input are solvable.
 */
void solvePuzzle()
{
    int   state;    // Combination of lights to test to solve the puzzle.
    int   popcount; // Number of lights to press in the current combination.
    light lights[WIDTH * HEIGHT]; // Arrays which contains the lights to press.

    state = 0;
    while (true) {
        popcount = 0;
        // We get the set bits, i.e. lights to press in the current combination.
        for (int i = 0; i < 30; ++i) {
            if (state & (1 << i)) {
                lights[popcount] = (light) {i: i / WIDTH, j: i % WIDTH };
                ++popcount;
            }
        }
        // We press the lights.
        for (int i = 0; i < popcount; ++i) {
          push(lights[i]);
        }
        if (checkPuzzle()) {
            // If the puzzle is solved, format it as required for output.
            // We mark lights to press with 1 and all others with 0.
            for (int  i = 0; i < popcount; ++i) {
                light l = lights[i];
                puzzle[l.i][l.j] = true;
            }
            return;
        } else {
            // The current combination does not work. We have to undo our moves.
            for (int i = 0; i < popcount; ++i){
                push(lights[i]);
            }
        }
        // We move to the next state.
        ++state;
    }
}

/**
 * Read a puzzle from stdin and return the number of lights turned on.
 */
int readPuzzle()
{
    int l, m;

    m = 0;
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            scanf("%d", &l);
            puzzle[i][j] = l;
            if (l == 1) {
                ++m;
            }
        }
    }

    return m;
}

int main()
{
    int  n, m;

    scanf("%d\n", &n);
    for (int t = 0; t < n; ++t) {
        m = readPuzzle();
        if (m > 0) {
            // We only need to solve a puzzle if at least one light is on.
            solvePuzzle();
        }
        printf("PUZZLE #%d\n", t + 1);
        printPuzzle();
    }

    return 0;
}
