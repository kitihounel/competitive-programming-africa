/**
 * Note:
 * This is the solution provided by the judges. We just change the formatting
 * to make the code eaiser to read.
 * We cannot provide better explainations than the one given here.
 * To understand the solution, you should be familiar with translation,
 * normal vectors and unit vectors.
 *
 * 2005 ACM Greater New York Regional Collegiate Programming Contest
 * Problem F -- Stacking Cylinders
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_DIST  3.46
#define MAX_CYLS	10
#define EPS	   .000001

typedef struct _dppoint_ {
    double x;
    double y;
} DPPoint, *pDPPoint;

/**
 * find center of cylinder on top (into pTop) from centers
 * of supporting cylinders (pLeft and pRight)
 * return 0 on OK non-zero for error
 * procedure: (supporting centers are (a,b) and (c,d)
 * new center is on perpendicular bisector of segment
 * joining supporting centers:
 * pt on line ((c+a)/2,(d+b)/2)
 * length of line r = sqrt((c-a)^2 + (d-b)^2)
 * unit vector in direction of perpendicular bisector
 * R = <-(d-b)/r, (c-a)/r>
 * line between left center and top center +
 * left half of line between left and right +
 * perpendicular bisector form a right triangle
 * hypotenuse = line between left and center = 4
 * side along line between left an right = r/2
 * so perp bisector side = t = sqrt(4 - (r/2)^2)
 * new center is at 
 * ((c+a)/2 - t*(d-b)/r, (d+b)/2 + t*(c-a)/r)
 * ASSUMES pLeft->x < pRight->x
 */

int SupportedCylinder(pDPPoint pLeft, pDPPoint pRight, pDPPoint pTop)
{
    double a, b, c, d, r, t, x, y;

    a = pLeft->x;
    b = pLeft->y;
    c = pRight->x;
    d = pRight->y;
    r = (c - a) * (c - a) + (d - b) * (d - b);
    r = sqrt(r);
    if ((r < 2.0) || (r > MAX_DIST)) {
        return -1;
    }

    t = sqrt(4.0 - (r / 2.0) * (r / 2.0));
    x = (c + a) / 2.0;
    y = (d + b) / 2.0;
    x -= (t * (d - b) / r);
    y += (t * (c - a) / r);
    pTop->x = x;
    pTop->y = y;

    return 0;
}

/*
 * parse inbuf of integer count followed by that many doubles
 * return count (or negative on error) put doubles in pVals
 */
int ParseInbuf(char *pBuf, double *pVals)
{
    int nvals, curval, len, pos;
    double dblval;

    len = strlen(pBuf);
    pos = 0;
    /* skip leading spaces */
    while (isspace(pBuf[pos])) {
        pos++;
        if (pos >= len) {
            return -4;
        }
    }

    /* now point at non-whitespace */
    /* get count */
    if (sscanf(&(pBuf[pos]), "%d", &nvals) != 1) {
        return -5;
    }

    if (nvals > MAX_CYLS) {
        return -9;
    }

    for (curval = 0; curval < nvals ; curval++) {
        /* skip over last value */
        while (!isspace(pBuf[pos])) {
            pos++;
            if (pos >= len) {
                return -6;
            }
        }

        /* skip over spaces */
        while (isspace(pBuf[pos])) {
            pos++;
            if (pos >= len) {
                return -7;
            }
        }

        /* read double value */
        if (sscanf(&(pBuf[pos]), "%lf", &dblval) != 1) {
            return -8;
        }

        pVals[curval] = dblval;
    }

    return nvals;
}

char    inbuf[256];
double  rdvals[MAX_CYLS];
DPPoint centers[MAX_CYLS][MAX_CYLS];

int main()
{
    int curset, nvals;
    int i, j, np, nProb;
    double test;

    if (fgets(&(inbuf[0]), 256, stdin) == NULL) {
        return 1;
    }

    nProb = atoi(&(inbuf[0]));

    curset = 0;
    for (np = 1; np <= nProb; np++) {
        if (fgets(&(inbuf[0]), 256, stdin) == NULL) {
            fprintf(stderr, "read failed getting data set %d\n", curset + 1);
            return -1;
        }

        nvals = ParseInbuf(&(inbuf[0]), &(rdvals[0]));
        if (nvals <= 0) {
            return nvals;
        }

        for (i = 0; i < nvals ; i++) {
            centers[0][i].x = rdvals[i];
            centers[0][i].y = 1.0;
        }

        test = 0.5 *(rdvals[0] + rdvals[nvals - 1]);
        for (i = 1; i < nvals ; i++) {
            for (j = 0; j < nvals - i; j++) {
                if (SupportedCylinder(&(centers[i-1][j]), &(centers[i-1][j+1]), &(centers[i][j])) != 0) {
                    fprintf(stderr, "SupportedCenters failed on row %d clinder %d\n", i, j);
                    return -10;
                }
            }
        }

        if (fabs(test - centers[nvals-1][0].x) > EPS) {
            fprintf(stderr, "dataset %d: test %.7lf val %.7lf\n", curset + 1, test, centers[nvals-1][0].x);
        }

        printf("%d: %.4lf %.4lf\n", np, centers[nvals-1][0].x, centers[nvals-1][0].y);
        curset++;
    }
    return 0;
}

