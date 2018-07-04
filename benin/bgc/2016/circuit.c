#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    int   n;
    char  concept, text[512], unit[3];
    bool  iFlag, pFlag, uFlag;
    char *s;
    long  double i, p, u;
    long  double m, v;

    scanf("%d\n", &n);
    for (int t = 1; t <= n; ++t) {
        fgets(text, 512, stdin);
        iFlag = pFlag = uFlag = false;
        s = strchr(text, '=');
        while (s != NULL) {
            sscanf(s - 1, "%c=%Lf%[mkMAVW]", &concept, &v, unit);
            if (strlen(unit) > 1ul) {
                m = unit[0] == 'M'? 1.e6l: (unit[0] == 'k'? 1.e3l: .001l);
            } else {
                m = 1.l;
            }
            switch (concept) {
            case 'I':
                iFlag = true;
                i = v * m;
                break;
            case 'P':
                pFlag = true;
                p = v * m;
                break;
            case 'U':
                uFlag = true;
                u = v * m;
                break;
            }
            s = strchr(s + 1, '=');
        }

        printf("Problem #%d\n", t);
        if (iFlag && uFlag) {
            printf("P=%.2LfW\n", u * i);
        } else if (iFlag && pFlag) {
            printf("U=%.2LfV\n", p / i);
        } else {
            printf("I=%.2LfA\n", p / u);
        }
        printf("\n");
    }

    return 0;
}
