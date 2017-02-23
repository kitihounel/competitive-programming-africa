#include <stdio.h>
#include <string.h>

/**
 * Evaluate the value of a simple arithmetic expression consisting of numbers,
 * and addition and minus operators.
 */
int eval(char *expr)
{
    int   answer, val;
    char *p;
    
    fprintf(stderr, "evaluating: %s\n", expr);
    answer = 0;
    p = expr;
    do {
        sscanf(p, "%d", &val);
        answer += val;
        p = strpbrk(p + 1, "+-");
    } while (p != NULL);
    fprintf(stderr, "result: %d\n", answer);

    return answer;
}

int main()
{
    char  expr[256], rightExpr[256];
    char *rightParenthesis, *leftParenthesis;
    char  ch;
    int   val;

    while(scanf("%s\n", expr) > 0) {
        leftParenthesis = strrchr(expr, '(');
        while(leftParenthesis != NULL) {
            rightParenthesis = strchr(leftParenthesis + 1, ')');
           *rightParenthesis = '\0';
            val = eval(leftParenthesis + 1);

            /* If the left parenthesis is not at the beginning of the */
            /* expression we have to take care of the sign. */
            if (leftParenthesis != expr) {
                ch = *(leftParenthesis - 1);
                switch (ch) {
                case '+':
                    if (val < 0) {
                        *(leftParenthesis - 1) = '-';
                        val = -val;
                    }
                    break;
                case '-':
                    if (val < 0) {
                        *(leftParenthesis - 1) = '+';
                        val = -val;
                    }
                    break;
                default:
                    /* Nothing to do. We don't even need a default case. */
                    ;
                }
            }
            
            /* Create the new expression by concatening the expression before */
            /* the left parenthesis, val, and the expression after the right */
            /* parenthesis. */
            strcpy(rightExpr, rightParenthesis + 1);
            sprintf(leftParenthesis, "%d", val);
            strcat(expr, rightExpr);

            leftParenthesis = strrchr(expr, '(');
        }

        printf("%d\n", eval(expr));
    }

    return 0;
}

