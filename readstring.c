#include <stdio.h>
#include <string.h>

#define BUFLEN 100

int main(void)
{

    int siz;
    char i[BUFLEN];

    printf("Enter a string.\n");
    fflush(stdout);
    fgets(i, BUFLEN, stdin);

    siz = strlen(i) - 1;

    printf("siz is %d\n", siz);
    
    printf("hit <return> to exit program\n");
    getc(stdin);
    return 0;
}
