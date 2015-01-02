/* Longest common sub-string is different from longest Common Subsequence(LCS).
 * In LCS, we take the longest among (m, n) by :
 *  - if string1[m] == string2[n] , lcs(m-1, n-1) + 1
 *  - else maximum(lcs(m, n-1), lcs(m-1, n))
 *
 *  But in case of Longest Common Sub-string :
 *  idea is to find length of the longest common suffix for all substrings of both strings
 *  - select a common suffix that is the longest
 *
 *  - if string1[m] == string2[n] , lcsuff(m-1, n-1) + 1
 *  - else lcsuff[m, n] = 0
 *  - Do it for all possible values of (m, n) and select the one with highest value.
 */
#include <stdio.h>
#include <string.h>
int start1, start2;

int
longest_common_substring(char *str1, char *str2)
{
    int i, j;
    int longest = 0;
    int len1, len2;
    len1 = strlen(str1);
    len2 = strlen(str2);
    int	lcsuff[len1+1][len2+1];
    
    for(i=0; i<=len1; i++)
    {
	for(j=0; j<=len2; j++)
	{
	    if(i ==0 || j==0)
		lcsuff[i][j] = 0;
	    else if (str1[i-1] == str2[j-1])
		lcsuff[i][j] = lcsuff[i-1][j-1] + 1;
	    else 
		lcsuff[i][j] = 0;
	    
	    /* Update the longest common substring */
	    if(longest < lcsuff[i][j])
	    {
		longest = lcsuff[i][j];
		start1 = i-1;
		start2 = j-1;
	    }
	}
    }

    return longest;
}

int
main()
{
    int  i=0, longest;
    char str1[100], str2[100];

    printf("String1 and String2	    :	");
    scanf("%s%s", str1, str2);

    longest = longest_common_substring(str1, str2);
    printf("Longest Common Substring	:   %d\n", longest);

    printf("String1 : ");
    for(i=start1-longest; i<=start1; i++)
	printf("%c ", str1[i]);
    printf("\nString2 : ");
    for(i=start2-longest; i<=start2; i++)
	printf("%c ", str2[i]);

    printf("\n------ Bye --------\n");
    return 0;
}
