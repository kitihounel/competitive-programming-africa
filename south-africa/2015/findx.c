/*
 * The solution implemented here is not the best. It would be better to use
 * a stack to evaluate the expression. Maybe you should implement your own
 * solution. It will be a good exercise :)
 *
 * Explaination.
 * We parse the equation one token at a time, starting from the left.
 * The parsing algorithm works as follow:
 *  + At start, we are on the left side of the equation.
 *
 *  + If the current item is an operator (`+` or `-`), it will have effect on
 *    the next item, so we store it in the variable `sign`.
 *
 *  + If the current item is a digit, we add its value to the side we are
 *    currently at.
 *      - The variable `lval` holds the value of the left side.
 *      - The variable `rval` holds the value of the right side.
 *
 *  + If the current item is a letter, we get our variable. We store it in
 *    the variable `var` and we store its sign in the variable 'varsign'.
 *
 *  + If the current item is the equality operator sign `=`, we "switch"
 *    to the right side.
 *
 * When we are done parsing the equation, we compute the value of the variable
 * by computing lval - rval. If the sign of the variable is `-`, we negate val.
 *
 * Note:
 *      When we move from left side to right side, we reset `sign` to `+`.
 *
 * Other variables:
 *      n: as in problem statement.
 *      varside: indicates the side of the equation the variable belongs to.
 *               0 => left side, 1 => right side.
 *      side: indicate at which side of the equation we are.
 *               0 => left side, 1 => right side.
 *      sign: 1 => positive, -1 => negative.
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int  n;
    int  lval, rval, ans;
    int  sign, side, varsign, varside;
    char equation[64], token, var;

    while(scanf("%d\n", &n) > 0 && n != -1) {
        scanf("%[a-z0-9 =+-]\n", equation);
        side = lval = rval = 0;
        sign = 1;

        char *pos = strtok(equation, " ");
        while (pos != NULL) {
            token = *pos;

            if (isalpha(token)) {
                /* We got our variable. */
                var     = token;
                varside = side;
                varsign = sign;
            } else if (isdigit(token)) {
                /* We got a digit. */
                switch (side) {
                case 0:
                    lval += (token - '0') * sign;
                    break;
                case 1:
                    rval += (token - '0') * sign;
                    break;
                }
            } else {
                /* Equality operator or sign. */
                switch (token) {
                case '+':
                    sign =  1;
                    break;
                case '-':
                    sign = -1;
                    break;
                default:
                    side = sign = 1;
                    break;
                }
            }

            /* We move to the next token. */
            pos = strtok(NULL, " ");
        }

        /* We can finally compute the value of the variable */
        if (varside) {
            ans = (lval - rval) * varsign;
        } else {
            ans = (rval - lval) * varsign;
        }
        printf("%c = %d\n", var, ans);
    }

    return 0;
}

