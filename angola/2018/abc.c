#include <stdio.h>
#include <stdlib.h>

int cmp(const void *p1, const void *p2)
{
    return *((const int *) p1) - *((const int *) p2); 
}

int main()
{
    int arr[3];
    char c1, c2, c3;

    scanf("%d %d %d\n", arr, arr + 1, arr + 2);
    qsort(arr, 3, sizeof(int), cmp);
    scanf("%c%c%c\n", &c1, &c2, &c3);
    printf("%d %d %d\n", arr[c1 - 65], arr[c2 - 65], arr[c3 - 65]);

    return 0;
}

