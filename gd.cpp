 #include <stdio.h>

 #define YES 1

 #define NO 0

main ()

{
    int ch;

    long nc=0L;

    int nl=0;

    int nw=0;

    int word=NO;

    while (( ch = getchar())!= EOF)

    {
        nc++;

        if (ch == '\n');

        nl++;

        if (ch != ' ' && ch != '\n' && ch != '\t' && word == NO)

    {
        word == YES;

        nw++;

    }

        if ((ch == ' ' || ch == '\n' || ch == '\t') && word == YES);

        word = NO;

    }

        printf ("sym is %1d, word is %d, lines are %d", nc, nw, nl);

}




