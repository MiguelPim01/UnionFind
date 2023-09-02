#ifndef UNION_FIND_H
#define UNION_FIND_H

typedef struct UnionFind UnionFind;

UnionFind *union_find_construct(int size);

int UF_find(UnionFind *uf, int i);

void UF_union(UnionFind *uf, int p, int q);

void union_find_destroy(UnionFind *uf);

#endif