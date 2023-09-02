#include <stdlib.h>

#include "unionFind.h"

struct UnionFind {
    int *floresta;
    int *sz;
    int size;
};

// O(N): Custo linear para alocar e inicializar
UnionFind *union_find_construct(int size)
{
    UnionFind *uf = (UnionFind *)malloc(sizeof(UnionFind));

    uf->size = size;
    uf->floresta = (int *)malloc(sizeof(int)*size);
    uf->sz = (int *)malloc(sizeof(int)*size);

    for (int i = 0; i < size; i++)
        uf->floresta[i] = i;
    for (int i = 0; i < size; i++)
        uf->sz[i] = 1;

    return uf;
}

int UF_find(UnionFind *uf, int i)
{
    while (i != uf->floresta[i])
    {
        uf->floresta[i] = uf->floresta[uf->floresta[i]];
        i = uf->floresta[i];
    }
    return i;
}

void UF_union(UnionFind *uf, int p, int q)
{
    int i = UF_find(uf, p);
    int j = UF_find(uf, q);
    if (i == j) return;

    if (uf->sz[i] < uf->sz[j])
    {
        uf->floresta[i] = j;
        uf->sz[j] += uf->sz[i];
    }
    else
    {
        uf->floresta[j] = i;
        uf->sz[i] += uf->sz[j];
    }
}

void union_find_destroy(UnionFind *uf)
{
    free(uf->floresta);
    free(uf);
}