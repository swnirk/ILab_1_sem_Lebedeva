#include <stdio.h>

unsigned int codeToNumber(char l1, char l2, char l3, char l4)

{
    int x1 = 0;

    x1 = (l1 - 'A' + 1) * 1000000 + (l2 - 'A' + 1) * 10000 + (l3 - 'A' + 1) * 100 + (l4 - 'A' + 1);

    return x1;

}

int main ()

{

    char l1, l2, l3, l4;

    scanf ("%c %c %c %c", &l1, &l2, &l3, &l4);

    unsigned int res = codeToNumber( l1, l2, l3, l4) ;
    printf ("%d", res);

    return 0;

}






