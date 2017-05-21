/**
 * We have two problems to solve here ;)
 * The simplest way to solve this problem is to use regular expressions.
 * Sadly, it not easy to use them in C, so the solution is given in C++. But if
 * you want a challenge, you can take a look at the regex.h header in GNU LibC.
 *
 * The regex used here will match a repetition of a digit in a string.
 * The solution was found here:
 * stackoverflow.com/questions/7735897/can-regular-expressions-find-repetitions-of-characters
 */
#include <iostream>
#include <cstdio>
#include <regex>
#include <string>

using namespace std;

int main()
{
    char   number[5];
    string target;
    regex  rgx("([0-9])\\1+");
    smatch sm;
    int    matchCount;

    while (scanf("%*s %s %*s\n", number) > 0 && number[0] != '#') {
        target = number;
        matchCount = 0;
        while (regex_search(target, sm, rgx)) {
            if (matchCount > 0) {
                printf(" and ");
            }
            printf("%c %c glued", sm.str()[0], sm.str()[0]);
            target = sm.suffix();
            ++matchCount;
        }

        if (matchCount > 0) {
            printf("\n");
        }
    }

    return 0;
}
