#include <stdio.h>
#include <string.h>

int main() {
    int n;
    printf("Size of the pattern: ");
    scanf("%d", &n);

    int lps[n];
    char pat[n];

    printf("Enter pattern character by character: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &pat[i]);
    }

    int i = 0, j = 1;
    lps[0] = 0;
    while (j < n) {
        if (pat[i] == pat[j]) {
            lps[j] = i + 1;
            i++;
            j++;
        } else {
            if (i == 0) {
                lps[j] = 0;
                j++;
            } else {
                i = lps[i - 1];
            }
        }
    }

    printf("LPS Array: ");
    for (int q = 0; q < n; q++) {
        printf("%d\t", lps[q]);
    }
    printf("\n");

    char txt[100];
    printf("Enter the text: ");
    scanf(" %[^\n]", txt);
    printf("%s\n", txt);

    int count = 0;
    int len = strlen(txt);
    int s = 0;

    while (s <= len - n) {
        int c = 0;
        int j = 0;

        for (; j < n; j++) {
            if (txt[s + j] == pat[j]) {
                c++;
            } else {
                if (j == 0) {
                    s++;
                } else {
                    s = lps[j - 1] + 1;
                }
                break;
            }
        }

        if (c == n) {
            printf("Pattern matched at %d\n", s);
            count++;
            s++;
        }
    }

    if (count == 0) {
        printf("Pattern not matched\n");
    } else {
        printf("The frequency of the pattern in the text is: %d\n", count);
    }

    return 0;
}

---------------------------------------------------------------------------------------------------------------------------------------------
  #output:
Size of the pattern: 2
Enter pattern character by character: i s
LPS Array: 0    0
Enter the text: is isis isisisisis
is isis isisisisis
Pattern matched at 0
Pattern matched at 3
Pattern matched at 5
Pattern matched at 8
Pattern matched at 10
Pattern matched at 12
Pattern matched at 14
Pattern matched at 16
The frequency of the pattern in the text is: 8
