#include <stdio.h>

int main()
{
    FILE *pFile;
    char caminho[20] = "in.txt";
    int N = 100;

    pFile = fopen(caminho, "w");

    fprintf(pFile, "%d\n", N);

    for (int i = 1; i < N; i++)
        fprintf(pFile, "UNION %d %d\n", i-1, i);
    
    for (int i = 0; i < N; i++)
        fprintf(pFile, "FIND %d\n", i);

    return 0;
}
