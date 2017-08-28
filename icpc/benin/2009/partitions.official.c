/*
 * Recursive partitions solution
 * by Fred Pickel
 * October 2008
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PROBS	1000
#define EPS	.001
#define ERR	.001

char inbuf[512];
int results[1010];
int lastMax;


/*
 * Let F(N) be the number of recursively palindromic partitions of N
 * if N is even, we can get a recursively palindromic partition by putting
 * any even number K <= N in the center and then a recursively palindromic
 * partition of (N-K)/2 on either side so
 * F(N) = 1 + F(2) + ... + F(N/2) = F(N-2) + F(N/2) (1 is the case where K = N)
 * if N is odd, we can get a recursively palindromic partition by putting
 * any odd number K <= N in the center and then a recursively palindromic
 * partition of (N-K)/2 on either side so
 * F(N) = 1 + F(2) + ... + F((N-1)/2) = F(N-1) (1 is the case where K = N)
 * 
 */
int CompResult(int val)
{
	int i;
	if(val <= lastMax)
	{
		return results[val];
	}
	for(i = lastMax+1; i <= val; i++)
	{
		if((i & 1) != 0)
		{
			results[i] = results[i-1];
		}
		else
		{
			results[i] = results[i-2] + results[i/2];
		}
	}
	lastMax = val;
	return results[val];
}

int main()
{
	int probCnt, curProb;
	int curN;

	results[0] = results[1] = 1;
	lastMax = 1;
	CompResult(1000);
	if(fgets(&(inbuf[0]), 255, stdin) == NULL)
	{
		fprintf(stderr, "read failed on problem count\n");
		return -1;
	}
	inbuf[255] = 0;
	probCnt = atoi(&(inbuf[0]));
	if((probCnt < 1) || (probCnt > MAX_PROBS))
	{
		fprintf(stderr, "Problem count %d not in range 1...%d\n", probCnt, MAX_PROBS);
		return -2;
	}
	for(curProb = 1; curProb <= probCnt ; curProb++)
	{
		if(fgets(&(inbuf[0]), 255, stdin) == NULL)
		{
			fprintf(stderr, "read failed on problem %d\n", curProb);
			return -3;
		}
		if(sscanf(&(inbuf[0]), "%d", &curN) != 1)
		{
			fprintf(stderr, "scan failed on problem %d\n", curProb);
			return -4;
		}
		if(curN > 1000)
		{
			fprintf(stderr, "N %d > 1000 on problem %d\n", curN, curProb);
			return -5;
		}
		printf("%d %d\n", curProb, results[curN]);
	}
	return 0;
}

