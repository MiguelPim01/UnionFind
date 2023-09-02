#include <stdio.h>
#include <string.h>
#include <time.h>

#include "unionFind.h"

int main()
{
    int N, u1, u2, result_find;
    char op[10];
    clock_t start, end;

    scanf("%d", &N);

    UnionFind *uf = union_find_construct(N);

    start = clock();
    while (scanf("\n%s", op) == 1)
    {
        if (!strcmp("UNION", op))
        {
            scanf("%d %d", &u1, &u2);

            UF_union(uf, u1, u2);
        }
        else if (!strcmp("FIND", op))
        {
            scanf("%d", &u1);

            result_find = UF_find(uf, u1);

            // printf("raiz de %d: %d\n", u1, result_find);
        }
    }
    end = clock();

    printf("time: %lf\n", (double)(end-start)/CLOCKS_PER_SEC); // Ordem de crescimento muito proxima de um crescimento linear

    union_find_destroy(uf);

    return 0;
}