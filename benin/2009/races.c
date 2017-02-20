#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char line[256];
    
    scanf("%d %s %s%*[ ]%[\x20-\x7E]\n");
}

