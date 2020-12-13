#include <stdio.h>
#include <string.h>
void search(char *pat, char *txt)
{
    int M = strlen(pat), N = strlen(txt), i, j;
    for (i = 0; i <= N - M; i++)
    {
        for (j = 0; j < M; j++)
            if (txt[i + j] != pat[j])
                break;

        if (j == M)
            printf("Pattern found at index %d \n", i);
    }
}
int main()
{
    char txt[100], pat[10];
    printf("Enter text:");
    scanf("%s", txt);
    printf("Enter Pattern:");
    scanf("%s", pat);
    search(pat, txt);
    return 0;
}
