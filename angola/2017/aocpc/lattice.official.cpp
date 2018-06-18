/**
 * ACM2006 Greater NY Region C++ Solution to F - Visible Points
 *
 * Fred Pickel
 * October, 2006
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

char inbuf[256];
int countsGCD[MAX_SIZE+1];

int GCD(int i, int j)
{
	int q;

	if(i == 0)
	{
		return j;
	}
	if(j == 0)
	{
		return i;
	}
	q = (i % j);
	while(q > 0)
	{
		i = j;
		j = q;
		q = (i % j);
	}
	return j;
}
		
void MakeGCDCounts()
{
	int i, j, cnt;
	countsGCD[0] = 0;
	countsGCD[1] = 3;
	for(i = 2 ; i <= MAX_SIZE ; i++)
	{
		cnt = 0;
		for(j = 1; j < i ; j++)
		{
			if(GCD(i,j) == 1)
			{
				cnt++;
			}
		}
		countsGCD[i] = countsGCD[i-1] + 2*cnt;
	}
}

void Init()
{
	MakeGCDCounts();
}

int main()
{
	int probnum, size, n;

	Init();

	if(fgets(&(inbuf[0]), sizeof(inbuf), stdin) == NULL){
		return -2;
	}
	n = atoi(&(inbuf[0]));
	for(probnum = 1; probnum <= n; probnum++)
	{
		if(fgets(&(inbuf[0]), sizeof(inbuf), stdin) == NULL){
		fprintf(stderr, "unexpected end of file on problem number %d\n", probnum);
			break;
		}

		if(sscanf(&(inbuf[0]), "%d", &size) != 1)
		{
			fprintf(stderr, "scan failed on problem number %d\n", probnum);
			return -1;
		}
		if((size <= 0) || (size > MAX_SIZE))
		{
			fprintf(stderr, "size %d out of range on problem number %d\n", size, probnum);
			return -2;
		}
		printf("%d %d %d\n", probnum, size, countsGCD[size]);
	}
	return 0;
}
