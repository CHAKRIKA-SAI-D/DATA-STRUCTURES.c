//brute force method
//pattern matching
#include <stdio.h>
#include <string.h>
int main() {
    char pat[100];
    printf("Enter pattern max(100) : ");
    scanf("%[^\n]s",pat);
    printf("%s is your pattern",pat);
    char txt[100];
    printf("\nEnter text  max(100) : ");
    scanf(" %[^\n]s",txt);
    printf("%s is your text",txt);
    int m=strlen(txt);
    int n=strlen(pat);
    int c = 0;
    for (int i = 0; i <= m; i++) {
        int t = 1;
        if (pat[0] == txt[i]) {
            for (int j = 1; j < n; j++) {
                if (i + j > m) {
                    break;
                } else {
                    if (pat[j] == txt[i + j]) {
                        t++;
                    }
                }
            }
            if (t == n) {
                c++;
                printf("\n pattern found at %d\n", i + 1);
            }
        }
    }
    printf("\nTotal occurrences: %d\n", c);
    return 0;
}
-------------------------------------------------------------------------------------------------------------
#output:
Enter pattern max(100) : for
for is your pattern
Enter text  max(100) : a for apple b for bat c for cat
a for apple b for bat c for cat is your text
 pattern found at 3

 pattern found at 15

 pattern found at 25

Total occurrences: 3
