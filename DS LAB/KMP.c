#include <stdio.h>
#include <string.h>
void LPSArray(char *pat, int M, int *lps)
{
	int len = 0 , i = 1;
	lps[0] = 0;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
                len = lps[len - 1];
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat) , N = strlen(txt) , lps[M];
    LPSArray(pat, M, lps);
    int i = 0 , j = 0;
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }
        if (j == M)
        {
            printf("Pattern Found at index %d\n", i - j);
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
}
void main()
{
    char txt[100], pat[20];
    printf("Enter Text:");
    scanf("%s", txt);
    printf("Enter Pattern:");
    scanf("%s", pat);
    KMPSearch(pat, txt);
}
